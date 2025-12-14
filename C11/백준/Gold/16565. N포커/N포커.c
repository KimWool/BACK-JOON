#include <stdio.h>

#define MOD 10007

int comb[53][53];

void buildComb() {
    for (int i = 0; i <= 52; i++) {
        comb[i][0] = comb[i][i] = 1;
        for (int j = 1; j < i; j++) {
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);

    buildComb();

    int result = 0;
    for (int k = 1; k <= 13 && 4 * k <= N; k++) {
        int a = comb[13][k];
        int b = comb[52 - 4 * k][N - 4 * k];
        int ways = (a * b) % MOD;

        if (k % 2 == 1)
            result = (result + ways) % MOD;
        else
            result = (result - ways + MOD) % MOD;
    }

    printf("%d\n", result);
    return 0;
}