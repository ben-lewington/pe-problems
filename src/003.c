#include "stdio.h"
#include <math.h>

#include "../lib/common.c"

#define N 600851475143

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
