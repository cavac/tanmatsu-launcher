// SPDX-License-Identifier: MIT
// Tanmatsu Plugin API Symbol Export Library for kbelf
// This file exports plugin API symbols to the dynamic linker.

#include <kbelf.h>

// External symbol references using asm attribute to get addresses
// Logging API
extern char const symbol_plugin_log_info[] asm("plugin_log_info");
extern char const symbol_plugin_log_warn[] asm("plugin_log_warn");
extern char const symbol_plugin_log_error[] asm("plugin_log_error");

// Display API
extern char const symbol_plugin_display_get_buffer[] asm("plugin_display_get_buffer");
extern char const symbol_plugin_display_flush[] asm("plugin_display_flush");
extern char const symbol_plugin_display_flush_region[] asm("plugin_display_flush_region");

// Status Bar Widget API
extern char const symbol_plugin_status_widget_register[] asm("plugin_status_widget_register");
extern char const symbol_plugin_status_widget_unregister[] asm("plugin_status_widget_unregister");

// Drawing Primitives API
extern char const symbol_plugin_draw_circle[] asm("plugin_draw_circle");
extern char const symbol_plugin_draw_rect[] asm("plugin_draw_rect");
extern char const symbol_plugin_draw_rect_outline[] asm("plugin_draw_rect_outline");
extern char const symbol_plugin_set_pixel[] asm("plugin_set_pixel");
extern char const symbol_plugin_draw_line[] asm("plugin_draw_line");
extern char const symbol_plugin_draw_text[] asm("plugin_draw_text");

// Input API
extern char const symbol_plugin_input_poll[] asm("plugin_input_poll");
extern char const symbol_plugin_input_get_key_state[] asm("plugin_input_get_key_state");

// Input Hook API
extern char const symbol_plugin_input_hook_register[] asm("plugin_input_hook_register");
extern char const symbol_plugin_input_hook_unregister[] asm("plugin_input_hook_unregister");
extern char const symbol_plugin_input_inject[] asm("plugin_input_inject");

// LED API
extern char const symbol_plugin_led_set_brightness[] asm("plugin_led_set_brightness");
extern char const symbol_plugin_led_get_brightness[] asm("plugin_led_get_brightness");
extern char const symbol_plugin_led_set_mode[] asm("plugin_led_set_mode");
extern char const symbol_plugin_led_get_mode[] asm("plugin_led_get_mode");
extern char const symbol_plugin_led_set_pixel[] asm("plugin_led_set_pixel");
extern char const symbol_plugin_led_set_pixel_rgb[] asm("plugin_led_set_pixel_rgb");
extern char const symbol_plugin_led_set_pixel_hsv[] asm("plugin_led_set_pixel_hsv");
extern char const symbol_plugin_led_send[] asm("plugin_led_send");
extern char const symbol_plugin_led_clear[] asm("plugin_led_clear");

// Storage API
extern char const symbol_plugin_storage_open[] asm("plugin_storage_open");
extern char const symbol_plugin_storage_read[] asm("plugin_storage_read");
extern char const symbol_plugin_storage_write[] asm("plugin_storage_write");
extern char const symbol_plugin_storage_seek[] asm("plugin_storage_seek");
extern char const symbol_plugin_storage_tell[] asm("plugin_storage_tell");
extern char const symbol_plugin_storage_close[] asm("plugin_storage_close");
extern char const symbol_plugin_storage_exists[] asm("plugin_storage_exists");
extern char const symbol_plugin_storage_mkdir[] asm("plugin_storage_mkdir");
extern char const symbol_plugin_storage_remove[] asm("plugin_storage_remove");

// Memory API
extern char const symbol_plugin_malloc[] asm("plugin_malloc");
extern char const symbol_plugin_calloc[] asm("plugin_calloc");
extern char const symbol_plugin_realloc[] asm("plugin_realloc");
extern char const symbol_plugin_free[] asm("plugin_free");

// Timer API
extern char const symbol_plugin_delay_ms[] asm("plugin_delay_ms");
extern char const symbol_plugin_get_tick_ms[] asm("plugin_get_tick_ms");
extern char const symbol_plugin_should_stop[] asm("plugin_should_stop");

// Menu API
extern char const symbol_plugin_menu_add_item[] asm("plugin_menu_add_item");
extern char const symbol_plugin_menu_remove_item[] asm("plugin_menu_remove_item");

// Event API
extern char const symbol_plugin_event_register[] asm("plugin_event_register");
extern char const symbol_plugin_event_unregister[] asm("plugin_event_unregister");

// Network API
extern char const symbol_plugin_net_is_connected[] asm("plugin_net_is_connected");
extern char const symbol_plugin_http_get[] asm("plugin_http_get");
extern char const symbol_plugin_http_post[] asm("plugin_http_post");

// Settings API
extern char const symbol_plugin_settings_get_string[] asm("plugin_settings_get_string");
extern char const symbol_plugin_settings_set_string[] asm("plugin_settings_set_string");
extern char const symbol_plugin_settings_get_int[] asm("plugin_settings_get_int");
extern char const symbol_plugin_settings_set_int[] asm("plugin_settings_set_int");

// Power Information API
extern char const symbol_plugin_power_get_battery_info[] asm("plugin_power_get_battery_info");
extern char const symbol_plugin_power_get_system_voltage[] asm("plugin_power_get_system_voltage");
extern char const symbol_plugin_power_get_battery_voltage[] asm("plugin_power_get_battery_voltage");
extern char const symbol_plugin_power_get_input_voltage[] asm("plugin_power_get_input_voltage");
extern char const symbol_plugin_power_get_charging_config[] asm("plugin_power_get_charging_config");
extern char const symbol_plugin_power_set_charging[] asm("plugin_power_set_charging");
extern char const symbol_plugin_power_get_usb_boost[] asm("plugin_power_get_usb_boost");
extern char const symbol_plugin_power_set_usb_boost[] asm("plugin_power_set_usb_boost");

// Symbol table
static kbelf_builtin_sym const symbols[] = {
    // Logging API
    { .name = "plugin_log_info", .vaddr = (size_t) symbol_plugin_log_info },
    { .name = "plugin_log_warn", .vaddr = (size_t) symbol_plugin_log_warn },
    { .name = "plugin_log_error", .vaddr = (size_t) symbol_plugin_log_error },

    // Display API
    { .name = "plugin_display_get_buffer", .vaddr = (size_t) symbol_plugin_display_get_buffer },
    { .name = "plugin_display_flush", .vaddr = (size_t) symbol_plugin_display_flush },
    { .name = "plugin_display_flush_region", .vaddr = (size_t) symbol_plugin_display_flush_region },

    // Status Bar Widget API
    { .name = "plugin_status_widget_register", .vaddr = (size_t) symbol_plugin_status_widget_register },
    { .name = "plugin_status_widget_unregister", .vaddr = (size_t) symbol_plugin_status_widget_unregister },

    // Drawing Primitives API
    { .name = "plugin_draw_circle", .vaddr = (size_t) symbol_plugin_draw_circle },
    { .name = "plugin_draw_rect", .vaddr = (size_t) symbol_plugin_draw_rect },
    { .name = "plugin_draw_rect_outline", .vaddr = (size_t) symbol_plugin_draw_rect_outline },
    { .name = "plugin_set_pixel", .vaddr = (size_t) symbol_plugin_set_pixel },
    { .name = "plugin_draw_line", .vaddr = (size_t) symbol_plugin_draw_line },
    { .name = "plugin_draw_text", .vaddr = (size_t) symbol_plugin_draw_text },

    // Input API
    { .name = "plugin_input_poll", .vaddr = (size_t) symbol_plugin_input_poll },
    { .name = "plugin_input_get_key_state", .vaddr = (size_t) symbol_plugin_input_get_key_state },

    // Input Hook API
    { .name = "plugin_input_hook_register", .vaddr = (size_t) symbol_plugin_input_hook_register },
    { .name = "plugin_input_hook_unregister", .vaddr = (size_t) symbol_plugin_input_hook_unregister },
    { .name = "plugin_input_inject", .vaddr = (size_t) symbol_plugin_input_inject },

    // LED API
    { .name = "plugin_led_set_brightness", .vaddr = (size_t) symbol_plugin_led_set_brightness },
    { .name = "plugin_led_get_brightness", .vaddr = (size_t) symbol_plugin_led_get_brightness },
    { .name = "plugin_led_set_mode", .vaddr = (size_t) symbol_plugin_led_set_mode },
    { .name = "plugin_led_get_mode", .vaddr = (size_t) symbol_plugin_led_get_mode },
    { .name = "plugin_led_set_pixel", .vaddr = (size_t) symbol_plugin_led_set_pixel },
    { .name = "plugin_led_set_pixel_rgb", .vaddr = (size_t) symbol_plugin_led_set_pixel_rgb },
    { .name = "plugin_led_set_pixel_hsv", .vaddr = (size_t) symbol_plugin_led_set_pixel_hsv },
    { .name = "plugin_led_send", .vaddr = (size_t) symbol_plugin_led_send },
    { .name = "plugin_led_clear", .vaddr = (size_t) symbol_plugin_led_clear },

    // Storage API
    { .name = "plugin_storage_open", .vaddr = (size_t) symbol_plugin_storage_open },
    { .name = "plugin_storage_read", .vaddr = (size_t) symbol_plugin_storage_read },
    { .name = "plugin_storage_write", .vaddr = (size_t) symbol_plugin_storage_write },
    { .name = "plugin_storage_seek", .vaddr = (size_t) symbol_plugin_storage_seek },
    { .name = "plugin_storage_tell", .vaddr = (size_t) symbol_plugin_storage_tell },
    { .name = "plugin_storage_close", .vaddr = (size_t) symbol_plugin_storage_close },
    { .name = "plugin_storage_exists", .vaddr = (size_t) symbol_plugin_storage_exists },
    { .name = "plugin_storage_mkdir", .vaddr = (size_t) symbol_plugin_storage_mkdir },
    { .name = "plugin_storage_remove", .vaddr = (size_t) symbol_plugin_storage_remove },

    // Memory API
    { .name = "plugin_malloc", .vaddr = (size_t) symbol_plugin_malloc },
    { .name = "plugin_calloc", .vaddr = (size_t) symbol_plugin_calloc },
    { .name = "plugin_realloc", .vaddr = (size_t) symbol_plugin_realloc },
    { .name = "plugin_free", .vaddr = (size_t) symbol_plugin_free },

    // Timer API
    { .name = "plugin_delay_ms", .vaddr = (size_t) symbol_plugin_delay_ms },
    { .name = "plugin_get_tick_ms", .vaddr = (size_t) symbol_plugin_get_tick_ms },
    { .name = "plugin_should_stop", .vaddr = (size_t) symbol_plugin_should_stop },

    // Menu API
    { .name = "plugin_menu_add_item", .vaddr = (size_t) symbol_plugin_menu_add_item },
    { .name = "plugin_menu_remove_item", .vaddr = (size_t) symbol_plugin_menu_remove_item },

    // Event API
    { .name = "plugin_event_register", .vaddr = (size_t) symbol_plugin_event_register },
    { .name = "plugin_event_unregister", .vaddr = (size_t) symbol_plugin_event_unregister },

    // Network API
    { .name = "plugin_net_is_connected", .vaddr = (size_t) symbol_plugin_net_is_connected },
    { .name = "plugin_http_get", .vaddr = (size_t) symbol_plugin_http_get },
    { .name = "plugin_http_post", .vaddr = (size_t) symbol_plugin_http_post },

    // Settings API
    { .name = "plugin_settings_get_string", .vaddr = (size_t) symbol_plugin_settings_get_string },
    { .name = "plugin_settings_set_string", .vaddr = (size_t) symbol_plugin_settings_set_string },
    { .name = "plugin_settings_get_int", .vaddr = (size_t) symbol_plugin_settings_get_int },
    { .name = "plugin_settings_set_int", .vaddr = (size_t) symbol_plugin_settings_set_int },

    // Power Information API
    { .name = "plugin_power_get_battery_info", .vaddr = (size_t) symbol_plugin_power_get_battery_info },
    { .name = "plugin_power_get_system_voltage", .vaddr = (size_t) symbol_plugin_power_get_system_voltage },
    { .name = "plugin_power_get_battery_voltage", .vaddr = (size_t) symbol_plugin_power_get_battery_voltage },
    { .name = "plugin_power_get_input_voltage", .vaddr = (size_t) symbol_plugin_power_get_input_voltage },
    { .name = "plugin_power_get_charging_config", .vaddr = (size_t) symbol_plugin_power_get_charging_config },
    { .name = "plugin_power_set_charging", .vaddr = (size_t) symbol_plugin_power_set_charging },
    { .name = "plugin_power_get_usb_boost", .vaddr = (size_t) symbol_plugin_power_get_usb_boost },
    { .name = "plugin_power_set_usb_boost", .vaddr = (size_t) symbol_plugin_power_set_usb_boost },
};

// Library definition
kbelf_builtin_lib const badge_elf_lib_plugin = {
    .path        = "libplugin.so",
    .symbols_len = sizeof(symbols) / sizeof(symbols[0]),
    .symbols     = symbols,
};
