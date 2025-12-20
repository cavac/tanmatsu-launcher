// SPDX-License-Identiefier: MIT
// SPDX-CopyRightText: 2025 Julian Scheffers

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "esp_log.h"
#include "kbelf.h"

static char const TAG[] = "kbelfx";

// Measure the length of `str`.
size_t kbelfq_strlen(char const* str) {
    return strlen(str);
}

// Copy string from `src` to `dst`.
void kbelfq_strcpy(char* dst, char const* src) {
    strcpy(dst, src);
}

// Find last occurrance of `c` in `str`.
char const* kbelfq_strrchr(char const* str, char c) {
    return strrchr(str, c);
}

// Compare string `a` to `b`.
bool kbelfq_streq(char const* a, char const* b) {
    return !strcmp(a, b);
}

// Copy memory from `src` to `dst`.
void kbelfq_memcpy(void* dst, void const* src, size_t nmemb) {
    memcpy(dst, src, nmemb);
}

// Fill memory `dst` with `c`.
void kbelfq_memset(void* dst, uint8_t c, size_t nmemb) {
    memset(dst, c, nmemb);
}

// Compare memory `a` to `b`.
bool kbelfq_memeq(void const* a, void const* b, size_t nmemb) {
    return !memcmp(a, b, nmemb);
}

// Memory allocator function to use for allocating metadata.
// User-defined.
void* kbelfx_malloc(size_t len) {
    return malloc(len);
}

// Memory allocator function to use for allocating metadata.
// User-defined.
void* kbelfx_realloc(void* mem, size_t len) {
    return realloc(mem, len);
}

// Memory allocator function to use for allocating metadata.
// User-defined.
void kbelfx_free(void* mem) {
    free(mem);
}

// Memory allocator function to use for loading program segments.
// Takes a segment with requested address and permissions and returns a segment with physical and virtual address
// information. Returns success status. User-defined.
bool kbelfx_seg_alloc(kbelf_inst inst, size_t segs_len, kbelf_segment* segs) {
    // Determine memory requirements.
    size_t min_va = SIZE_MAX, max_va = 0, min_align = 16;
    for (size_t i = 0; i < segs_len; i++) {
        if (min_align < segs[i].alignment) min_align = segs[i].alignment;
        if (min_va > segs[i].vaddr_req) min_va = segs[i].vaddr_req;
        if (max_va < segs[i].vaddr_req + segs[i].size) max_va = segs[i].vaddr_req + segs[i].size;
    }

    // Allocate memory as requested.
    void* memory = aligned_alloc(min_align, max_va - min_va);
    if (!memory) return false;
    segs[0].alloc_cookie = memory;

    // Update actual virtual address fields.
    size_t offset = (size_t)memory - min_va;
    for (size_t i = 0; i < segs_len; i++) {
        segs[i].laddr = segs[i].vaddr_real = segs[i].vaddr_req + offset;
        ESP_LOGI(TAG, "Segment %p mapped to %p", (void*)segs[i].vaddr_req, (void*)segs[i].vaddr_real);
    }

    return true;
}

// Memory allocator function to use for loading program segments.
// Takes a previously allocated segment and unloads it.
// User-defined.
void kbelfx_seg_free(kbelf_inst inst, size_t segs_len, kbelf_segment* segs) {
    (void)inst;
    (void)segs_len;
    free(segs[0].alloc_cookie);
}

// Open a binary file for reading.
// User-defined.
void* kbelfx_open(char const* path) {
    return fopen(path, "rb");
}

// Close a file.
// User-defined.
void kbelfx_close(void* fd) {
    fclose(fd);
}

// Reads a number of bytes from a file.
// Returns the number of bytes read, or less than that on error.
// User-defined.
long kbelfx_read(void* fd, void* buf, long buf_len) {
    return fread(buf, 1, buf_len, fd);
}

// Reads a number of bytes from a file to a load address in the program.
// Returns the number of bytes read, or less than that on error.
// User-defined.
long kbelfx_load(kbelf_inst inst, void* fd, kbelf_laddr laddr, kbelf_laddr file_size, kbelf_laddr mem_size) {
    (void)inst;
    ESP_LOGI(TAG, "Loading 0x%x bytes from 0x%x to %p", (int)file_size, (int)ftell(fd), (void*)laddr);
    memset((void*)(laddr + file_size), 0, mem_size - file_size);
    return fread((void*)laddr, 1, file_size, fd);
}

// Sets the absolute offset in the file.
// Returns 0 on success, -1 on error.
// User-defined.
int kbelfx_seek(void* fd, long pos) {
    return fseek(fd, pos, SEEK_SET);
}

// Read bytes from a load address in the program.
bool kbelfx_copy_from_user(kbelf_inst inst, void* buf, kbelf_laddr laddr, size_t len) {
    (void)inst;
    memcpy(buf, (void const*)laddr, len);
    return true;
}

// Write bytes to a load address in the program.
bool kbelfx_copy_to_user(kbelf_inst inst, kbelf_laddr laddr, void* buf, size_t len) {
    (void)inst;
    memcpy((void*)laddr, buf, len);
    return true;
}

// Get string length from a load address in the program.
ptrdiff_t kbelfx_strlen_from_user(kbelf_inst inst, kbelf_laddr laddr) {
    (void)inst;
    return (ptrdiff_t)strlen((char const*)laddr);
}

// Find and open a dynamic library file.
// Returns non-null on success, NULL on error.
// User-defined.
kbelf_file kbelfx_find_lib(char const* needed) {
    return kbelf_file_open(needed, NULL);
}

extern kbelf_builtin_lib const badge_elf_lib_badge;
extern kbelf_builtin_lib const badge_elf_lib_c;
extern kbelf_builtin_lib const badge_elf_lib_gcc;
extern kbelf_builtin_lib const badge_elf_lib_m;
extern kbelf_builtin_lib const badge_elf_lib_pax_gfx;
extern kbelf_builtin_lib const badge_elf_lib_pax_codecs;
extern kbelf_builtin_lib const badge_elf_lib_pthread;
extern kbelf_builtin_lib const badge_elf_lib_plugin;

// Array of built-in libraries.
// Optional user-defined.
kbelf_builtin_lib const* kbelfx_builtin_libs[] = {
    &badge_elf_lib_badge, &badge_elf_lib_c,       &badge_elf_lib_gcc,
    &badge_elf_lib_m,     &badge_elf_lib_pax_gfx, &badge_elf_lib_pax_codecs, &badge_elf_lib_pthread,
    &badge_elf_lib_plugin,
};

// Number of built-in libraries.
// Optional user-defined.
size_t kbelfx_builtin_libs_len = sizeof(kbelfx_builtin_libs) / sizeof(void*);
