#include "doxy_smoke/callbacks.h"

static ds_callbacks g_cb = {0};

ds_err ds_set_callbacks(ds_callbacks cb) {
    g_cb = cb;
    return DS_OK;
}

void ds_emit_log(int level, const char* msg) {
    if (g_cb.logger) {
        g_cb.logger(level, msg, g_cb.user);
    }
}
