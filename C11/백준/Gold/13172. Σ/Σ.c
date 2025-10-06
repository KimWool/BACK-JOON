#include <stdio.h>

#define MOD 1000000007

long long mod_pow(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

int main() {
    int M;
    scanf("%d", &M);
    long long result = 0;
    for (int i = 0; i < M; i++) {
        long long N, S;
        scanf("%lld %lld", &N, &S);
        long long invN = mod_pow(N, MOD - 2);
        result = (result + (S * invN) % MOD) % MOD;
    }
    printf("%lld\n", result);
    return 0;
}