#include <stdbool.h>
#include <stdio.h>
#include <math.h>

#define N 3
#define NSTART (int)pow(10, N - 1)
#define NEND (int)pow(10, N)

bool is_palindrome(long num) {
    long n = num;
    long len = (long)log10(n);
    while (n >= 0) {
        long top = n / (long)pow(10, len);
        long bottom = n % 10;

        if (top != bottom) return false;

        if (len <= 1) return true;

        n = (n - top * (long)pow(10, len)) / 10;
        len = len - 2;
    }
    return true;
}

int main(void) {
    long max_palindrome = 0;
    for (long i = NSTART; i < NEND; ++i) {
        for (long j = NSTART; j < NEND; ++j) {
            long n = i * j;
            if (is_palindrome(n) && (n > max_palindrome)) max_palindrome = n;
        }
    }
    printf("max palindrome = %zu\n", max_palindrome);
}
