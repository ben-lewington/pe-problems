#include <stdbool.h>
#include <stdio.h>

#include "../lib/common.c"

#define N 10001

int main(void) {
    int p = 2;
    int pn = 1;
    int i = 0;
    while (pn < N) {
        ++i;
        if (is_composite(2*i + 1)) continue;
        p = 2*i + 1;
        ++pn;
    }
    printf("%dth prime: %d\n", N, p);

    return 0;
}

