#include <stdbool.h>
#include <stdio.h>

#include "../lib/common.c"

#define N 10001

int main(void) {
    IterPrimes ip = primes_new();

    for (long i = 0; i < N - 1; ++i) {
        primes_next(&ip);
    }

    printf("%dth prime: %zu\n", N, primes_next(&ip));

    return 0;
}

