#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        int sticker[2][100001] = {0};
        for (int i = 1; i <= n; i++) scanf("%d", &sticker[0][i]);
        for (int i = 1; i <= n; i++) scanf("%d", &sticker[1][i]);
        int dp[2][100001] = {0};
        dp[0][1] = sticker[0][1];
        dp[1][1] = sticker[1][1];
        for (int i = 2; i <= n; i++) {
            dp[0][i] = (dp[1][i-1] > dp[1][i-2] ? dp[1][i-1] : dp[1][i-2]) + sticker[0][i];
            dp[1][i] = (dp[0][i-1] > dp[0][i-2] ? dp[0][i-1] : dp[0][i-2]) + sticker[1][i];
        }
        int ans = dp[0][n] > dp[1][n] ? dp[0][n] : dp[1][n];
        printf("%d\n", ans);
    }
    return 0;
}