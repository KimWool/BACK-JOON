#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

long long power(long long base, int exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int main() {
    int n;
    scanf("%d", &n);
    int capsaicin[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &capsaicin[i]);
    }

    qsort(capsaicin, n, sizeof(int), compare);

    long long result = 0;
    for (int i = 0; i < n; i++) {
        long long add = (capsaicin[i] * power(2, i)) % MOD;
        long long sub = (capsaicin[i] * power(2, n - 1 - i)) % MOD;
        result = (result + add - sub + MOD) % MOD;
    }

    printf("%lld\n", result);
    return 0;
}