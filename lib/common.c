#ifndef COMMON_FUNCTIONS_IMPL
#define COMMON_FUNCTIONS_IMPL

#include <stdbool.h>
#define COMMON_FUNCTIONS_SQRT_AFTER pow(10, 5)

bool is_composite(long n) {
    // long b = (n > COMMON_FUNCTIONS_SQRT_AFTER) ? (long)sqrt(n): n;

    for (int i = 2; i < n; ++i) {
        if (n % i == 0) return true;
    }
    return false;
}

#else
    bool is_composite(long n);
#endif // COMMON_FUNCTIONS_IMPL

