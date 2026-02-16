#ifndef MONEY_H
#define MONEY_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>

/* Non-doxygen comment: your tool should NOT replace this by default. */
typedef struct Money Money;

/** Already documented: must be skipped. */
int money_is_valid(const Money* m);

/* --- Symbols below should receive Doxygen comments --- */

typedef enum Currency {
    CUR_EUR = 0,
    CUR_USD = 1,
    CUR_GBP = 2
} Currency;

struct Money {
    int64_t cents;
    Currency currency;
};

Money money_make(int64_t cents, Currency currency);

int money_add(const Money* a, const Money* b, Money* out);

int money_format(const Money* m, char* buf, size_t buf_len);

/* Macro edge case: your tool may skip macros safely. */
#define MONEY_ABS(x) ((x) < 0 ? -(x) : (x))

#ifdef __cplusplus
}
#endif

#endif /* MONEY_H */
