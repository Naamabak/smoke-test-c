#include "doxy_smoke/api.h"
#include <stdlib.h>
#include <string.h>

/**
 * @brief Check if the multiplication of two size_t values would result in an arithmetic overflow.
 * @param a The first factor.
 * @param b The second factor.
 * @return 1 if the multiplication would overflow, 0 otherwise.
 */
static int would_overflow(size_t a, size_t b) {
    return (a > (SIZE_MAX - b)) ? 1 : 0;
}

ds_buffer ds_buffer_make(size_t initial_cap) {
    ds_buffer b;
    b.len = 0;
    b.cap = (initial_cap == 0) ? 16 : initial_cap;
    b.data = (uint8_t*)malloc(b.cap);
    return b;
}

ds_err ds_buffer_append(ds_buffer* b, const void* bytes, size_t n) {
    if (!b || (!bytes && n > 0)) return DS_ERR_INVALID_ARG;
    if (would_overflow(b->len, n)) return DS_ERR_OVERFLOW;

    size_t need = b->len + n;
    if (need > b->cap) {
        size_t new_cap = b->cap * 2;
        while (new_cap < need) new_cap *= 2;
        uint8_t* p = (uint8_t*)realloc(b->data, new_cap);
        if (!p) return DS_ERR_OVERFLOW;
        b->data = p;
        b->cap = new_cap;
    }

    if (n > 0) memcpy(b->data + b->len, bytes, n);
    b->len = need;
    return DS_OK;
}

const uint8_t* ds_buffer_data(const ds_buffer* b) {
    return b ? b->data : NULL;
}

size_t ds_buffer_size(const ds_buffer* b) {
    return b ? b->len : 0;
}

void ds_buffer_free(ds_buffer* b) {
    if (!b) return;
    free(b->data);
    b->data = NULL;
    b->len = 0;
    b->cap = 0;
}
