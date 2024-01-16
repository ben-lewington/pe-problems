#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#define N 20
#define SQRT_AFTER pow(10, 4)

long min(long l, long r) {
    if (l < r) return r; else return l;
}

long greatest_common_divisor(long n, long m) {
    long out = 1;
    long b = min(m, n);
    if (b > SQRT_AFTER) b = (long)sqrt((double)b);
    for (long p = 2; p <= b; ++p) {
        while (n % p == 0 && m % p == 0) {
            n /= p;
            m /= p;
            out *= p;
        }
    }
    return out;
}

int main(void) {
    long acc = 1;
    for (long i = 2; i <= N; ++i) acc *= i / greatest_common_divisor(i, acc);
    printf("acc: %zu\n", acc);

    return 0;
}
