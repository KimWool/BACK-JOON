#include <stdio.h>
#define MOD 1000000000

int dp[101][10][1024];

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 1; i <= 9; i++) {
        dp[1][i][1 << i] = 1;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k < 1024; k++) {
                if (j > 0) {
                    dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j - 1][k]) % MOD;
                }
                if (j < 9) {
                    dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j + 1][k]) % MOD;
                }
            }
        }
    }

    int result = 0;
    for (int i = 0; i <= 9; i++) {
        result = (result + dp[N][i][1023]) % MOD;
    }

    printf("%d\n", result);
    return 0;
}