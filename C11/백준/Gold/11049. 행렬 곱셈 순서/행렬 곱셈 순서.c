#include <stdio.h>
#include <limits.h>

int r[500], c[500];
int dp[500][500];

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &r[i], &c[i]);
    }

    for (int len = 1; len < N; len++) {
        for (int i = 0; i + len < N; i++) {
            int j = i + len;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + r[i] * c[k] * c[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    printf("%d\n", dp[0][N - 1]);
    return 0;
}