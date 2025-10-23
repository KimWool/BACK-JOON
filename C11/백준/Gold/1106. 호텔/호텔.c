#include <stdio.h>
#define INF 1000000

int main() {
    int C, N;
    scanf("%d %d", &C, &N);

    int dp[1101];
    for (int i = 0; i < 1101; i++) dp[i] = INF;
    dp[0] = 0;

    for (int i = 0; i < N; i++) {
        int cost, customer;
        scanf("%d %d", &cost, &customer);
        for (int j = customer; j < 1101; j++) {
            if (dp[j - customer] + cost < dp[j]) {
                dp[j] = dp[j - customer] + cost;
            }
        }
    }

    int result = INF;
    for (int i = C; i < 1101; i++) {
        if (dp[i] < result) result = dp[i];
    }

    printf("%d\n", result);
    return 0;
}