#include <stdio.h>

int main() {

    long N, M;
    scanf("%ld %ld", &N, &M);

    long A = (N < M) ? N : M;
    long B = (N > M) ? N : M;

    long sum = ((B * (B + 1)) / 2) - ((A - 1) * A / 2);

    printf("%ld", sum);

    return 0;
}