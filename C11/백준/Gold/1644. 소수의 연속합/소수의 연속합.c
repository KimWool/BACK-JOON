#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d", &n);

    bool* isPrime = (bool*)malloc((n + 1) * sizeof(bool));
    for (int i = 0; i <= n; i++) {
        isPrime[i] = true;
    }
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    int* primes = (int*)malloc((n + 1) * sizeof(int));
    int primeCount = 0;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes[primeCount++] = i;
        }
    }

    int count = 0;
    int start = 0, end = 0, sum = 0;

    while (1) {
        if (sum >= n) {
            if (sum == n) count++;
            sum -= primes[start++];
        } else {
            if (end == primeCount) break;
            sum += primes[end++];
        }
    }

    printf("%d\n", count);

    free(isPrime);
    free(primes);
    return 0;
}