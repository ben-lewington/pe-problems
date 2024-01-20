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
    IterPrimes ip = { .scanned_upto = 1 };
    return ip;
}

long primes_next(IterPrimes *ip) {
    if (ip->scanned_upto < 3) {
        ip->scanned_upto += 1;
        return ip->scanned_upto;
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

typedef struct {
    long p;
    int n_p;
} Factor;

typedef struct {
    long n;
    IterPrimes cur_p;
} IterFactors;

IterFactors factors_new(long n) {
    IterFactors factors = { .n = n, };

    factors.cur_p = primes_new();

    primes_next(&factors.cur_p);

    // skip 2 if n is odd
    if (n & 1) primes_next(&factors.cur_p);

    return factors;
}

Factor factors_next(IterFactors *factors) {
    Factor f = { 0 };
    if (factors->n == 1) return f;
    f.p = factors->cur_p.scanned_upto;

    while (factors->n % f.p != 0) {
        f.p = primes_next(&factors->cur_p);
    }

    while (factors->n % f.p == 0) {
        factors->n /= f.p;
        f.n_p++;
    }

    return f;
}

long factors_count(long n) {
    IterFactors ifs = factors_new(n);

    long i = 1;
    while (1) {
        Factor f = factors_next(&ifs);
        i *= f.n_p + 1;
        if (ifs.n == 1) return i;
    }
}

#else
    bool is_composite(long n);
#endif // COMMON_FUNCTIONS_IMPL
