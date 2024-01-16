#include "stdio.h"
#include "stdbool.h"
#include <math.h>

#define N 600851475143

bool is_composite(int n) {
    for (int i = 2; i < n; ++i) {
        if (n % i == 0) return true;
    }
    return false;
}

int main(void) {
    long bound = (long)sqrt((double)N);

    long value = N;
    long max_p = 1;
    long cur_p = 2 + (N & 1);

    while (value > 1) {
        while (cur_p < bound) {
            if (is_composite(cur_p)) {
                cur_p++;
                continue;
            }
            while (value % cur_p == 0) value /= cur_p;
            max_p = cur_p;
            cur_p++;
            break;
        }
    }
    printf("max: %zu\n", max_p);
    return 0;
}
