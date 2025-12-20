// SPDX-License-Identifier: MIT
// Tanmatsu Plugin Manager Header
// Handles plugin discovery, loading, unloading, and lifecycle management.

#pragma once

#include <stdbool.h>
#include <stddef.h>
#include "tanmatsu_plugin.h"
#include "plugin_context.h"

#ifdef __cplusplus
extern "C" {
#endif

// Maximum number of simultaneously loaded plugins
#define PLUGIN_MAX_LOADED 32

// Plugin discovery result
typedef struct {
    char* path;                 // Full path to plugin directory
    char* slug;                 // Plugin slug from metadata
    char* name;                 // Display name
    char* version;              // Version string
    plugin_type_t type;         // Plugin type
    bool is_loaded;             // Currently loaded?
} plugin_discovery_info_t;

// ============================================
// Plugin Manager Lifecycle
// ============================================

// Initialize plugin manager subsystem
bool plugin_manager_init(void);

// Shutdown plugin manager and unload all plugins
void plugin_manager_shutdown(void);

// ============================================
// Plugin Discovery
// ============================================

// Discover plugins in /int/plugins/ and /sd/plugins/
// Returns count of discovered plugins
// Caller must free with plugin_manager_free_discovery()
size_t plugin_manager_discover(plugin_discovery_info_t** out_plugins);

// Free discovered plugins list
void plugin_manager_free_discovery(plugin_discovery_info_t* plugins, size_t count);

// ============================================
// Plugin Loading/Unloading
// ============================================

// Load a plugin by path
// Returns plugin context on success, NULL on failure
plugin_context_t* plugin_manager_load(const char* plugin_path);

// Unload a plugin
bool plugin_manager_unload(plugin_context_t* ctx);

// ============================================
// Plugin Query
// ============================================

// Get loaded plugin by slug
plugin_context_t* plugin_manager_get_by_slug(const char* slug);

// Get all loaded plugins of a specific type
// Returns number of plugins found
size_t plugin_manager_get_by_type(plugin_type_t type,
                                   plugin_context_t** out_plugins,
                                   size_t max_count);

// Get count of loaded plugins
size_t plugin_manager_get_loaded_count(void);

// ============================================
// Service Plugin Management
// ============================================

// Start a service plugin (creates FreeRTOS task)
bool plugin_manager_start_service(plugin_context_t* ctx);

// Stop a service plugin
bool plugin_manager_stop_service(plugin_context_t* ctx);

// ============================================
// Event Dispatch
// ============================================

// Dispatch event to all hook plugins
// Returns number of plugins that handled the event
int plugin_manager_dispatch_event(uint32_t event_type, void* event_data);

// ============================================
// Autostart Management
// ============================================

// Enable/disable auto-start for a plugin
bool plugin_manager_set_autostart(const char* slug, bool enabled);

// Check if plugin has autostart enabled
bool plugin_manager_get_autostart(const char* slug);

// ============================================
// Status Widget Integration
// ============================================

// Get status widgets from loaded plugins
// Called by render_base_screen_statusbar()
size_t plugin_manager_get_status_widgets(plugin_icontext_t* out, size_t max,
                                          int start_x, int start_y);

#ifdef __cplusplus
}
#endif
