#include <stdio.h>
#include "money.h"

int main(void) {
    Money a = money_make(12345, CUR_EUR);
    Money b = money_make(100, CUR_EUR);

    Money sum;
    int rc = money_add(&a, &b, &sum);

    char buf[64];
    money_format(&sum, buf, sizeof(buf));

    printf("rc=%d sum=%s\n", rc, buf);
    return 0;
}
