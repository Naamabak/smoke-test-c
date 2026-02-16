#include "doxy_smoke/api.h"
#include <assert.h>

int main(void) {
    ds_buffer b = ds_buffer_make(8);
    const char x[] = "abc";
    assert(ds_buffer_append(&b, x, 3) == DS_OK);
    assert(ds_buffer_size(&b) == 3);
    ds_buffer_free(&b);
    return 0;
}
