#include <stdio.h>
#define INF 1000000

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n;
    scanf("%d", &n);
    
    int cost[1001][3];
    int dp[1001][3];
    
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
    }

    int result = INF;

    for (int first = 0; first < 3; first++) {
        for (int i = 0; i < 3; i++) {
            if (i == first) dp[1][i] = cost[1][i];
            else dp[1][i] = INF;
        }

        for (int i = 2; i <= n; i++) {
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];
        }

        for (int last = 0; last < 3; last++) {
            if (last == first) continue;
            if (result > dp[n][last]) result = dp[n][last];
        }
    }

    printf("%d\n", result);
    return 0;
}