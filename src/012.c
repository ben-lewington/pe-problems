#include <stdio.h>

#include "../lib/common.c"

#define TRI_NUM(N) ((N) * (N + 1)) / 2
#define FIRST_TRI_WITH_DIVISOR_COUNT 500

int main(void) {
    long i = 1;
    long tri = 1;
    long max_factors = 1;
    while (1) {
        long x = factors_count(tri);
        if (x > max_factors) max_factors = x;
        if (factors_count(tri) > FIRST_TRI_WITH_DIVISOR_COUNT) break;
        tri = TRI_NUM(i);
        i++;
    }
    printf("first number with over %zu divisors: %zu\n", (long)FIRST_TRI_WITH_DIVISOR_COUNT, tri);
    return 0;
}
