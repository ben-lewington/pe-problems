#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#define N 100

//  x = (S(1, N){i}) ^ 2 - (S(1, N){i^2})
//
//  S(1, N){i} === N*(N+1)/2
//  S(1, N){i^2} === N(N+1)(2*N+1) / 6
//
//  (S(1, N){i})^2 - S(1,N){i^2} =  N^2*(N+1)^2/4          - N(N+1)(2N + 1) / 6
//  (S(1, N){i})^2 - S(1,N){i^2} =  N^2*(N^2 + 2*N + 1)/4  - N(2N^2 + 3N + 1) / 6
//  (S(1, N){i})^2 - S(1,N){i^2} =  (N^4 + 2*N^3 + N^2)/4  - (2N^3 + 3N^2 + N) / 6
//  (S(1, N){i})^2 - S(1,N){i^2} =  (3*N^4 + 6*N^3 + 3*N^2 - (4N^3 + 6N^2 + 2N) ) / 12
//  (S(1, N){i})^2 - S(1,N){i^2} =  (3*N^4 + 6*N^3 + 3*N^2 - 4N^3 - 6N^2 - 2N) ) / 12
//  (S(1, N){i})^2 - S(1,N){i^2} =  (3*N^4 + 2*N^3 - 3*N^2 - 2*N) ) / 12
int main(void) {
    printf("(sum{1, N} i) ^ 2 - sum{1, N} i^2 = %zu",
           (3*(long)pow(N, 4)  + 2*(long)pow(N, 3) - 3*(long)pow(N, 2) - 2*N) / 12);
    return 0;
}

