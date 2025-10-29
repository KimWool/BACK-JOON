#include <stdio.h>
#include <string.h>

int A[2001];
int dp[2001][2001];

int main() {
    int N, M;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
    }

    for (int i = 1; i <= N; i++) {
        dp[i][i] = 1;
    }

    for (int i = 1; i < N; i++) {
        if (A[i] == A[i + 1]) {
            dp[i][i + 1] = 1;
        }
    }

    for (int len = 3; len <= N; len++) {
        for (int s = 1; s <= N - len + 1; s++) {
            int e = s + len - 1;
            if (A[s] == A[e] && dp[s + 1][e - 1]) {
                dp[s][e] = 1;
            }
        }
    }

    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int S, E;
        scanf("%d %d", &S, &E);
        printf("%d\n", dp[S][E]);
    }

    return 0;
}