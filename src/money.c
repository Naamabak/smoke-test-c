/*
 * Copyright (c) 2026.
 * Smoke test file for Doxygen insertion.
 */

#include "money.h"

static int currency_is_supported(Currency c) {
    return c == CUR_EUR || c == CUR_USD || c == CUR_GBP;
}

/* Already has Doxygen: must be skipped. */
/**
 * @brief Returns 1 if the Money object looks valid.
 */
int money_is_valid(const Money* m) {
    return m != NULL && currency_is_supported(m->currency);
}

Money money_make(int64_t cents, Currency currency) {
    Money m;
    m.cents = cents;
    m.currency = currency;
    return m;
}

int money_add(const Money* a, const Money* b, Money* out) {
    if (!a || !b || !out) return -1;
    if (a->currency != b->currency) return -2;
    out->currency = a->currency;
    out->cents = a->cents + b->cents;
    return 0;
}

int money_format(const Money* m, char* buf, size_t buf_len) {
    if (!m || !buf || buf_len == 0) return -1;

    const char* sym = "?";
    switch (m->currency) {
        case CUR_EUR: sym = "€"; break;
        case CUR_USD: sym = "$"; break;
        case CUR_GBP: sym = "£"; break;
        default: sym = "?"; break;
    }

    /* very naive formatting for testing */
    int64_t abs_cents = (m->cents < 0) ? -m->cents : m->cents;
    int64_t euros = abs_cents / 100;
    int64_t cents = abs_cents % 100;

    int n = snprintf(buf, buf_len, "%s%lld.%02lld",
                     sym,
                     (long long)euros,
                     (long long)cents);

    return (n < 0 || (size_t)n >= buf_len) ? -2 : 0;
}
