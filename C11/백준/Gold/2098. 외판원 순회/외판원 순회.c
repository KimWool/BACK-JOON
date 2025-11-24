#include <stdio.h>
#include <string.h>

#define INF 10000000

int N;
int W[16][16];
int dp[16][1 << 16];

int tsp(int current, int visited) {
    if (visited == (1 << N) - 1) {
        if (W[current][0] == 0) return INF;
        return W[current][0];
    }

    if (dp[current][visited] != -1) return dp[current][visited];

    dp[current][visited] = INF;

    for (int i = 0; i < N; i++) {
        if ((visited & (1 << i)) == 0 && W[current][i] != 0) {
            int cost = tsp(i, visited | (1 << i)) + W[current][i];
            if (dp[current][visited] > cost)
                dp[current][visited] = cost;
        }
    }

    return dp[current][visited];
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &W[i][j]);

    memset(dp, -1, sizeof(dp));

    printf("%d\n", tsp(0, 1));
    return 0;
}