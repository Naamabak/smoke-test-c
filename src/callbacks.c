#include "doxy_smoke/callbacks.h"

static ds_callbacks g_cb = {0};

/**
 * @brief Register the callback functions for the data stream.
 * @param cb The structure containing the callback function pointers.
 * @return A ds_err status code indicating the result of the operation.
 */
ds_err ds_set_callbacks(ds_callbacks cb) {
    g_cb = cb;
    return DS_OK;
}

/**
 * @brief Dispatch a formatted message to the logging system at a specified severity level.
 * @param level The severity level associated with the message.
 * @param msg The null-terminated string containing the message to be logged.
 */
void ds_emit_log(int level, const char* msg) {
    if (g_cb.logger) {
        g_cb.logger(level, msg, g_cb.user);
    }
}
