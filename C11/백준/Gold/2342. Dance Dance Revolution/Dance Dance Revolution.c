#include <stdio.h>
#include <stdlib.h>
#define INF 1000000000

int dp[100001][5][5];
int arr[100001];

int cost(int from, int to) {
    if (from == 0) return 2;
    if (from == to) return 1;
    if (abs(from - to) == 2) return 4;
    return 3;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n, idx = 0;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        arr[idx++] = n;
    }

    for (int i = 0; i <= idx; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                dp[i][j][k] = INF;
            }
        }
    }

    dp[0][0][0] = 0;

    for (int i = 0; i < idx; i++) {
        int next = arr[i];
        for (int l = 0; l < 5; l++) {
            for (int r = 0; r < 5; r++) {
                if (dp[i][l][r] == INF) continue;
                int moveLeft = dp[i][l][r] + cost(l, next);
                int moveRight = dp[i][l][r] + cost(r, next);
                if (moveLeft < dp[i + 1][next][r])
                    dp[i + 1][next][r] = moveLeft;
                if (moveRight < dp[i + 1][l][next])
                    dp[i + 1][l][next] = moveRight;
            }
        }
    }

    int answer = INF;
    for (int l = 0; l < 5; l++) {
        for (int r = 0; r < 5; r++) {
            if (dp[idx][l][r] < answer)
                answer = dp[idx][l][r];
        }
    }

    printf("%d\n", answer);
    return 0;
}