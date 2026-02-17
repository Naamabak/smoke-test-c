#include "doxy_smoke/callbacks.h"

static ds_callbacks g_cb = {0};

/**
 * @brief Set the callback functions for the data stream.
 * @param cb The callback structure containing function pointers to be registered.
 * @return The status of the operation as a ds_err value.
 */
ds_err ds_set_callbacks(ds_callbacks cb) {
    g_cb = cb;
    return DS_OK;
}

/**
 * @brief Log a message at a specified severity level.
 * @param level The severity level of the log entry.
 * @param msg The string message to be logged.
 */
void ds_emit_log(int level, const char* msg) {
    if (g_cb.logger) {
        g_cb.logger(level, msg, g_cb.user);
    }
}
