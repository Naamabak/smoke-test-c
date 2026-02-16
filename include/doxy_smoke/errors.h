#ifndef DOXY_SMOKE_ERRORS_H
#define DOXY_SMOKE_ERRORS_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum ds_err {
    DS_OK = 0,
    DS_ERR_INVALID_ARG = -1,
    DS_ERR_NOT_FOUND   = -2,
    DS_ERR_OVERFLOW    = -3
} ds_err;

#ifdef __cplusplus
}
#endif

#endif
