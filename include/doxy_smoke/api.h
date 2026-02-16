#ifndef DOXY_SMOKE_API_H
#define DOXY_SMOKE_API_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>
#include "doxy_smoke/errors.h"

typedef struct ds_buffer ds_buffer;

/**
 * @brief Represents a data structure for a buffer.
 */
struct ds_buffer {
    uint8_t* data;
    size_t len;
    size_t cap;
};

/**
 * @brief Create a new ds_buffer instance with a specified initial capacity.
 * @param initial_cap The starting capacity for the buffer.
 * @return A ds_buffer structure initialized with the given capacity.
 */
ds_buffer ds_buffer_make(size_t initial_cap);
/**
 * @brief Appends a specified number of bytes to a buffer.
 *
 * @param b Pointer to the buffer structure.
 * @param bytes Pointer to the data to be appended.
 * @param n Number of bytes to append.
 * @return A status code of type ds_err indicating the result of the operation.
 */
ds_err ds_buffer_append(ds_buffer* b, const void* bytes, size_t n);
/**
 * @brief Get a pointer to the buffer's data.
 * @param b Pointer to the buffer structure.
 * @return Pointer to the result, or NULL on failure.
 */
const uint8_t* ds_buffer_data(const ds_buffer* b);
/**
 * @brief Get the size of the buffer.
 * @param b Pointer to the buffer structure.
 * @return The size of the buffer as a size_t.
 */
size_t ds_buffer_size(const ds_buffer* b);
/**
 * @brief Deallocates the memory associated with the buffer.
 * @param b Pointer to the buffer structure to be freed.
 */
void ds_buffer_free(ds_buffer* b);

int main(int argc, char** argv);

#define DS_MIN(a,b) ((a) < (b) ? (a) : (b))
#define DS_UNUSED(x) (void)(x)

#ifdef __cplusplus
}
#endif

#endif
