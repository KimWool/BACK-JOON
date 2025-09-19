#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    int W[N + 1], V[N + 1];
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &W[i], &V[i]);
    }
    int dp[N + 1][K + 1];
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - W[i] >= 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - W[i]] + V[i]);
            }
        }
    }
    printf("%d\n", dp[N][K]);
    return 0;
}