#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int triangle[501][501] = {0};
    int dp[501][501] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", &triangle[i][j]);
        }
    }
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                dp[i][j] = dp[i-1][j] + triangle[i][j];
            } else if (j == i) {
                dp[i][j] = dp[i-1][j-1] + triangle[i][j];
            } else {
                dp[i][j] = (dp[i-1][j-1] > dp[i-1][j] ? dp[i-1][j-1] : dp[i-1][j]) + triangle[i][j];
            }
        }
    }
    int result = 0;
    for (int i = 0; i < n; i++) {
        if (dp[n-1][i] > result) result = dp[n-1][i];
    }
    printf("%d\n", result);
    return 0;
}