#include "stdio.h"

#define N 4000000

int main(void) {
    int sum = 0;
    int f0, f1 = 1;
    while (f1 + f0 < N) {
        int t = f0;
        f0 = f1;
        f1 += t;
        if (f1 % 2 == 0) sum += f1;
    }
    printf("%d\n", sum);
    return 0;
}
