
// SPDX-License-Identiefier: MIT
// SPDX-CopyRightText: 2025 Julian Scheffers

#include "badge_elf.h"
#include <stdio.h>
#include "esp_log.h"
#include "hal/cache_hal.h"
#include "kbelf.h"
#include "soc/soc.h"
#include "sdkconfig.h"

#if CONFIG_BOOTLOADER_REGION_PROTECTION_ENABLE
#error Please disable CONFIG_BOOTLOADER_REGION_PROTECTION_ENABLE
#endif

static char const TAG[] = "badge-elf";

// Start an ELF-based application.
bool badge_elf_start(char const* elf_path) {
    // Load the executable into memory.
    kbelf_dyn dyn = kbelf_dyn_create(0);
    if (!dyn) return false;
    ESP_LOGI(TAG, "Opening dynamic executable %s", elf_path);
    if (!kbelf_dyn_set_exec(dyn, elf_path, NULL) || !kbelf_dyn_load(dyn)) {
        kbelf_dyn_destroy(dyn);
        return false;
    }

#if SOC_CACHE_WRITEBACK_SUPPORTED
    // Sync insn and data caches.
    // TODO: If the ELF loader told us the base and size, this could be more optimal, but this works.
    cache_hal_writeback_addr(SOC_DRAM_LOW, SOC_DRAM_HIGH - SOC_DRAM_LOW);
#endif

    // Run its constructor array.
    size_t preinit_count = kbelf_dyn_preinit_len(dyn);
    ESP_LOGI(TAG, "Running %zu preinit func%s", preinit_count, preinit_count == 1 ? "" : "s");
    for (size_t i = 0; i < preinit_count; i++) {
        void (*func)() = (void*)kbelf_dyn_preinit_get(dyn, i);
        func();
    }
    size_t init_count = kbelf_dyn_init_len(dyn);
    ESP_LOGI(TAG, "Running %zu init func%s", init_count, init_count == 1 ? "" : "s");
    for (size_t i = 0; i < init_count; i++) {
        void (*func)() = (void*)kbelf_dyn_init_get(dyn, i);
        func();
    }

    // Run the entry function in a new thread.
    void (*entry)(int, char const**, char const**) = (void*)kbelf_dyn_entrypoint(dyn);
    ESP_LOGI(TAG, "Jumping to main @ %p", entry);
    entry(1, (char const*[]){elf_path}, (char const*[]){NULL});

    // Run its destructor array.
    size_t fini_count = kbelf_dyn_fini_len(dyn);
    ESP_LOGI(TAG, "Running %zu fini func%s", fini_count, fini_count == 1 ? "" : "s");
    for (size_t i = 0; i < fini_count; i++) {
        void (*func)() = (void*)kbelf_dyn_fini_get(dyn, i);
        func();
    }

    // Unload it again.
    ESP_LOGI(TAG, "Cleaning up after %s", elf_path);
    kbelf_dyn_unload(dyn);
    kbelf_dyn_destroy(dyn);

    return true;
}
