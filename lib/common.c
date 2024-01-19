#ifndef COMMON_FUNCTIONS_IMPL
#define COMMON_FUNCTIONS_IMPL

#include <math.h>
#include <stdbool.h>
#define COMMON_FUNCTIONS_SQRT_AFTER pow(10, 5)

bool is_composite_upto(long n, long check_upto) {
    for (long i = 2; i < check_upto; ++i) {
        if (n % i == 0) return true;
    }
    return false;
}

bool is_composite(long n) {
    return is_composite_upto(n, n);
}

typedef struct {
    long scanned_upto;
} IterPrimes;

IterPrimes primes_new() {
    IterPrimes ip = {
        .scanned_upto = 1,
    };
    return ip;
}

long primes_next(IterPrimes *ip) {
    if (ip->scanned_upto == 1) {
        ip->scanned_upto = 2;
        return 2;
    } else if (ip->scanned_upto == 2) {
        ip->scanned_upto = 3;
        return 3;
    } else {
        long f = (ip->scanned_upto / 2) + 1;
        while (true) {
            long n = 2*f + 1;
            long bound = (n > 100000) ? (long)sqrt(n) + 1: n;
            if (is_composite_upto(n, bound)) {
                ++f;
                continue;
            }

            ip->scanned_upto = n;
            return n;
        }
    }
}

#else
    bool is_composite(long n);
#endif // COMMON_FUNCTIONS_IMPL
