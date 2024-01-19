#include <stdbool.h>
#include <stdint.h>
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
// From (3), we have:
//     a^2 + b^2         == c^2
//     a^2 + b^2         == (1000 - (a + b))^2                      | from (2), c = 1000 - (a + b)
//     a^2 + b^2         == 1000^2 - 2*(a + b) + (a + b)^2
//     (a + b)^2 - 2*a*b == 1000^2 - 2*(a + b) + (a + b)^2
//     2*(a + b) - 2*a*b == 1000^2
// =>
//     a + b - a*b == 500_000
//     a*b = 500_000 - (a + b)
// thus we have:
//     abc == (ab)(c)
//         == (500_000 - (a + b))(1000 - (a + b))
//         == 500_000_000 - 501_000(a + b) - (a + b)^2)
//
// a + b + c == 1000
//
// a^2 + b^2 == c^2
// b^2 == (c - a)(c + a)
// b^2 == (1000 - 2a - b)(1000 - b)
//
// b^2 / (1000 - b) == 1000 - 2a - b
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
