// SPDX-License-Identifier: MIT
// Stub library for plugin linking
// These stubs are used at link time to create proper ELF dependencies.
// At runtime, kbelf resolves these symbols from the host.

// Logging API
void plugin_log_info(const char* tag, const char* format, ...) {}
void plugin_log_warn(const char* tag, const char* format, ...) {}
void plugin_log_error(const char* tag, const char* format, ...) {}

// Display API
void* plugin_display_get_buffer(void) { return 0; }
void plugin_display_flush(void) {}
void plugin_display_flush_region(int x, int y, int w, int h) {}

// Status Bar Widget API
int plugin_status_widget_register(void* callback, void* user_data) { return 0; }
void plugin_status_widget_unregister(int widget_id) {}

// Drawing Primitives API
void plugin_draw_circle(void* buffer, int cx, int cy, int radius, unsigned int color) {}
void plugin_draw_rect(void* buffer, int x, int y, int w, int h, unsigned int color) {}
void plugin_draw_rect_outline(void* buffer, int x, int y, int w, int h, unsigned int color) {}
void plugin_set_pixel(void* buffer, int x, int y, unsigned int color) {}
void plugin_draw_line(void* buffer, int x0, int y0, int x1, int y1, unsigned int color) {}
int plugin_draw_text(void* buffer, int x, int y, int font_size, unsigned int color, const char* text) { return 0; }

// Input API
int plugin_input_poll(void* event) { return 0; }
int plugin_input_get_key_state(int key) { return 0; }

// Input Hook API
int plugin_input_hook_register(void* callback, void* user_data) { return 0; }
void plugin_input_hook_unregister(int hook_id) {}
int plugin_input_inject(void* event) { return 0; }

// LED API
int plugin_led_set_brightness(unsigned char percentage) { return 0; }
int plugin_led_get_brightness(unsigned char* out_percentage) { return 0; }
int plugin_led_set_mode(int automatic) { return 0; }
int plugin_led_get_mode(int* out_automatic) { return 0; }
int plugin_led_set_pixel(unsigned int index, unsigned int color) { return 0; }
int plugin_led_set_pixel_rgb(unsigned int index, unsigned char r, unsigned char g, unsigned char b) { return 0; }
int plugin_led_set_pixel_hsv(unsigned int index, unsigned short hue, unsigned char sat, unsigned char val) { return 0; }
int plugin_led_send(void) { return 0; }
int plugin_led_clear(void) { return 0; }

// Storage API
void* plugin_storage_open(const char* path, const char* mode) { return 0; }
int plugin_storage_read(void* file, void* buffer, int size) { return 0; }
int plugin_storage_write(void* file, const void* buffer, int size) { return 0; }
int plugin_storage_seek(void* file, long offset, int whence) { return 0; }
long plugin_storage_tell(void* file) { return 0; }
void plugin_storage_close(void* file) {}
int plugin_storage_exists(const char* path) { return 0; }
int plugin_storage_mkdir(const char* path) { return 0; }
int plugin_storage_remove(const char* path) { return 0; }

// Memory API
void* plugin_malloc(unsigned int size) { return 0; }
void* plugin_calloc(unsigned int nmemb, unsigned int size) { return 0; }
void* plugin_realloc(void* ptr, unsigned int size) { return 0; }
void plugin_free(void* ptr) {}

// Timer API
void plugin_delay_ms(unsigned int ms) {}
unsigned int plugin_get_tick_ms(void) { return 0; }
int plugin_should_stop(void* ctx) { return 0; }

// Menu API
int plugin_menu_add_item(const char* label, void* callback, void* user_data) { return 0; }
void plugin_menu_remove_item(int item_id) {}

// Event API
int plugin_event_register(int event_type, void* callback, void* user_data) { return 0; }
void plugin_event_unregister(int registration_id) {}

// Network API
int plugin_net_is_connected(void) { return 0; }
int plugin_http_get(const char* url, void* response, int max_len) { return 0; }
int plugin_http_post(const char* url, const void* data, int data_len, void* response, int max_len) { return 0; }

// Settings API
int plugin_settings_get_string(const char* key, char* value, int max_len) { return 0; }
int plugin_settings_set_string(const char* key, const char* value) { return 0; }
int plugin_settings_get_int(const char* key, int* value) { return 0; }
int plugin_settings_set_int(const char* key, int value) { return 0; }
