#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LEN 5
#define MAX_DIGITS 10
#define MAX_NUM_LEN 15

int allowed[10];

int isPrime(long long n) {
    if (n < 2) return 0;
    if (n == 2 || n == 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    }
    return 1;
}

int canMake(const char* s) {
    for (int i = 0; s[i]; i++) {
        if (!allowed[s[i] - '0']) return 0;
    }
    return 1;
}

void generate(char* current, int length, int depth) {
    if (depth == length) {
        if (current[0] == '0' && length > 1) return;
        current[depth] = '\0';
        long long num = atoll(current);
        if (!isPrime(num)) {
            printf("YES\n%s\n", current);
            exit(0);
        }
        return;
    }
    for (int i = 0; i < 10; i++) {
        if (allowed[i]) {
            current[depth] = '0' + i;
            generate(current, length, depth + 1);
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int d;
        scanf("%d", &d);
        allowed[d] = 1;
    }

    if (canMake("1")) {
        printf("YES\n1\n");
        return 0;
    }

    const char* singleNonPrimes[] = {"0", "1", "4", "6", "8", "9"};
    for (int i = 0; i < 6; i++) {
        if (canMake(singleNonPrimes[i])) {
            printf("YES\n%s\n", singleNonPrimes[i]);
            return 0;
        }
    }

    char current[MAX_NUM_LEN];
    for (int len = 1; len <= 4; len++) {
        generate(current, len, 0);
    }

    printf("NO\n");
    return 0;
}