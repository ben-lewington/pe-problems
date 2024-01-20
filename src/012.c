#include <stdio.h>

#include "../lib/common.c"

#define TRI_NUM(N) ((N) * (N + 1)) / 2
#define FIRST_TRI_WITH_DIVISOR_COUNT 500

int main(void) {
    long i = 1;
    long tri = 1;
    while (1) {
        if (factors_count(tri) > FIRST_TRI_WITH_DIVISOR_COUNT) break;
        tri = TRI_NUM(i);
        i++;
    }
    printf("first number with over %zu divisors: %zu\n", (long)FIRST_TRI_WITH_DIVISOR_COUNT, tri);
    return 0;
}
