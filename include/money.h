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

/**
 * @brief Represents a monetary value using a fixed-point decimal or integer-based currency representation.
 */
struct Money {
    int64_t cents;
    Currency currency;
};

/**
 * @brief Creates a Money object from a specified amount in cents and a currency.
 * @param cents The amount of money represented in the smallest currency unit.
 * @param currency The currency type to be associated with the amount.
 * @return A Money structure initialized with the provided values.
 */
Money money_make(int64_t cents, Currency currency);

/**
 * @brief Adds two Money objects and stores the result in an output parameter.
 * @param a Pointer to the first Money operand.
 * @param b Pointer to the second Money operand.
 * @param out Pointer to the Money object where the result will be stored.
 * @return 0 on success, non-zero on error.
 */
int money_add(const Money* a, const Money* b, Money* out);

/**
 * @brief Formats a Money object into a character buffer.
 * @param m Pointer to the Money object to be formatted.
 * @param buf Pointer to the destination buffer where the formatted string is stored.
 * @param buf_len The size of the destination buffer in bytes.
 * @return 0 on success, non-zero on error.
 */
int money_format(const Money* m, char* buf, size_t buf_len);

/* Macro edge case: your tool may skip macros safely. */
#define MONEY_ABS(x) ((x) < 0 ? -(x) : (x))

#ifdef __cplusplus
}
#endif

#endif /* MONEY_H */
