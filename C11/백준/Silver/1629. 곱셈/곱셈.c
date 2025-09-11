#include <stdio.h>

long long A, B, C;

long long pow_mod(long long a, long long b) {
    if (b == 0) return 1;
    long long half = pow_mod(a, b / 2);
    long long result = (half * half) % C;
    if (b % 2 == 1) result = (result * a) % C;
    return result;
}

int main() {
    scanf("%lld %lld %lld", &A, &B, &C);
    printf("%lld\n", pow_mod(A % C, B));
    return 0;
}