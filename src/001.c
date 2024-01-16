#include "stdio.h"

#define N 1000

int main(void) {
    int sum = 0;
    for (unsigned int i=3; i < N; ++i) {
        if (i % 3 == 0 || i % 5 == 0) sum += i;
    }
    printf("%d\n", sum);
    return 0;
}
