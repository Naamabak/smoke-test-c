#ifndef DOXY_SMOKE_API_H
#define DOXY_SMOKE_API_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>
#include "doxy_smoke/errors.h"

typedef struct ds_buffer ds_buffer;

struct ds_buffer {
    uint8_t* data;
    size_t len;
    size_t cap;
};

ds_buffer ds_buffer_make(size_t initial_cap);
ds_err ds_buffer_append(ds_buffer* b, const void* bytes, size_t n);
const uint8_t* ds_buffer_data(const ds_buffer* b);
size_t ds_buffer_size(const ds_buffer* b);
void ds_buffer_free(ds_buffer* b);

int main(int argc, char** argv);

#define DS_MIN(a,b) ((a) < (b) ? (a) : (b))
#define DS_UNUSED(x) (void)(x)

#ifdef __cplusplus
}
#endif

#endif
