#include <stdbool.h>
#include <stdio.h>

#include "../lib/common.c"

#define N 2000000

int main(void) {
    long sum = 0;
    IterPrimes ip = primes_new();

    for (long i = 0; true; ++i) {
        long p = primes_next(&ip);
        if (p >= N) break;

        sum += p;
    }

    printf("sum %zu\n", sum);

    return 0;
}
