// WARNING: This is a generated file, do not edit it!
// clang-format off

#include <kbelf.h>

extern char const symbol_asp_audio_set_rate[] asm("asp_audio_set_rate");
extern char const symbol_asp_audio_get_volume[] asm("asp_audio_get_volume");
extern char const symbol_asp_audio_set_volume[] asm("asp_audio_set_volume");
extern char const symbol_asp_audio_set_amplifier[] asm("asp_audio_set_amplifier");
extern char const symbol_asp_audio_stop[] asm("asp_audio_stop");
extern char const symbol_asp_audio_start[] asm("asp_audio_start");
extern char const symbol_asp_audio_write[] asm("asp_audio_write");
extern char const symbol_asp_device_get_name[] asm("asp_device_get_name");
extern char const symbol_asp_device_get_manufacturer[] asm("asp_device_get_manufacturer");
extern char const symbol_asp_disp_get_params[] asm("asp_disp_get_params");
extern char const symbol_asp_disp_get_fb[] asm("asp_disp_get_fb");
extern char const symbol_asp_disp_get_pax_buf[] asm("asp_disp_get_pax_buf");
extern char const symbol_asp_disp_init_pax_buf[] asm("asp_disp_init_pax_buf");
extern char const symbol_asp_disp_write[] asm("asp_disp_write");
extern char const symbol_asp_disp_write_pax[] asm("asp_disp_write_pax");
extern char const symbol_asp_disp_write_part[] asm("asp_disp_write_part");
extern char const symbol_asp_disp_write_part_pax[] asm("asp_disp_write_part_pax");
extern char const symbol_asp_err_id[] asm("asp_err_id");
extern char const symbol_asp_err_desc[] asm("asp_err_desc");
extern char const symbol_asp_input_poll[] asm("asp_input_poll");
extern char const symbol_asp_input_get_nav[] asm("asp_input_get_nav");
extern char const symbol_asp_input_get_action[] asm("asp_input_get_action");
extern char const symbol_asp_input_needs_on_screen_keyboard[] asm("asp_input_needs_on_screen_keyboard");
extern char const symbol_asp_input_set_backlight[] asm("asp_input_set_backlight");
extern char const symbol_asp_input_get_backlight[] asm("asp_input_get_backlight");

static kbelf_builtin_sym const symbols[] = {
    { .name = "asp_audio_set_rate", .vaddr = (size_t) symbol_asp_audio_set_rate },
    { .name = "asp_audio_get_volume", .vaddr = (size_t) symbol_asp_audio_get_volume },
    { .name = "asp_audio_set_volume", .vaddr = (size_t) symbol_asp_audio_set_volume },
    { .name = "asp_audio_set_amplifier", .vaddr = (size_t) symbol_asp_audio_set_amplifier },
    { .name = "asp_audio_stop", .vaddr = (size_t) symbol_asp_audio_stop },
    { .name = "asp_audio_start", .vaddr = (size_t) symbol_asp_audio_start },
    { .name = "asp_audio_write", .vaddr = (size_t) symbol_asp_audio_write },
    { .name = "asp_device_get_name", .vaddr = (size_t) symbol_asp_device_get_name },
    { .name = "asp_device_get_manufacturer", .vaddr = (size_t) symbol_asp_device_get_manufacturer },
    { .name = "asp_disp_get_params", .vaddr = (size_t) symbol_asp_disp_get_params },
    { .name = "asp_disp_get_fb", .vaddr = (size_t) symbol_asp_disp_get_fb },
    { .name = "asp_disp_get_pax_buf", .vaddr = (size_t) symbol_asp_disp_get_pax_buf },
    { .name = "asp_disp_init_pax_buf", .vaddr = (size_t) symbol_asp_disp_init_pax_buf },
    { .name = "asp_disp_write", .vaddr = (size_t) symbol_asp_disp_write },
    { .name = "asp_disp_write_pax", .vaddr = (size_t) symbol_asp_disp_write_pax },
    { .name = "asp_disp_write_part", .vaddr = (size_t) symbol_asp_disp_write_part },
    { .name = "asp_disp_write_part_pax", .vaddr = (size_t) symbol_asp_disp_write_part_pax },
    { .name = "asp_err_id", .vaddr = (size_t) symbol_asp_err_id },
    { .name = "asp_err_desc", .vaddr = (size_t) symbol_asp_err_desc },
    { .name = "asp_input_poll", .vaddr = (size_t) symbol_asp_input_poll },
    { .name = "asp_input_get_nav", .vaddr = (size_t) symbol_asp_input_get_nav },
    { .name = "asp_input_get_action", .vaddr = (size_t) symbol_asp_input_get_action },
    { .name = "asp_input_needs_on_screen_keyboard", .vaddr = (size_t) symbol_asp_input_needs_on_screen_keyboard },
    { .name = "asp_input_set_backlight", .vaddr = (size_t) symbol_asp_input_set_backlight },
    { .name = "asp_input_get_backlight", .vaddr = (size_t) symbol_asp_input_get_backlight },
};

kbelf_builtin_lib const badge_elf_lib_badge = {
    .path        = "libbadge.so",
    .symbols_len = 25,
    .symbols     = symbols,
};
