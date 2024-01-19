#include <stdbool.h>
#include <stdio.h>
#include <math.h>
// Given:
//     (1) a < b < c
//
//     (2) a^2 + b^2 = c^2
//
//     (3) a + b + c == 1000
//
//
// Find abc
//
// a + b + c == 1000
//
// a^2 + b^2 == c^2
// a^2 == (c - b)(c + b)
// a^2 == (1000 - 2b - a)(1000 - a)
//
// a^2 / (1000 - a) == 1000 - 2b - a
//
// b = (1000 - a - a^2 / (1000 - a)) / 2

int main(void) {
    long a = 0;
    long b = 0;
    long c = 0;
    for (a = 1; a < 1000; ++a) {
        long x = 1000 - a;
        long y = a * a;

        if (y % x != 0) continue;

        long z = y / x;

        if (x < z) continue;

        long t = x - z;

        if (t % 2 != 0 || t == 0) continue;

        b = t / 2;

        if (a > b) continue;

        long csq = a*a + b*b;
        c = (long)sqrt(csq);
        break;
    }
    printf("%zu\n", a*b*c);
    return 0;
}
