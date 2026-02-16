#ifndef DOXY_SMOKE_CALLBACKS_H
#define DOXY_SMOKE_CALLBACKS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include "doxy_smoke/errors.h"

typedef void (*ds_log_fn)(int level, const char* msg, void* user);

typedef struct ds_callbacks {
    ds_log_fn logger;
    void* user;
} ds_callbacks;

/**
 * @brief Set the callback functions for the data stream.
 * @param cb The callback structure to be registered.
 * @return The status of the operation as a ds_err value.
 */
ds_err ds_set_callbacks(ds_callbacks cb);

/** @brief Emits a log message (used internally). */
void ds_emit_log(int level, const char* msg);

#ifdef __cplusplus
}
#endif

#endif
