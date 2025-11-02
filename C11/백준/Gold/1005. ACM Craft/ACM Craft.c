#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1001

int D[MAX], dp[MAX], indegree[MAX];
int adj[MAX][MAX];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, K;
        scanf("%d %d", &N, &K);

        for (int i = 1; i <= N; i++) {
            scanf("%d", &D[i]);
            dp[i] = 0;
            indegree[i] = 0;
            for (int j = 1; j <= N; j++) adj[i][j] = 0;
        }

        for (int i = 0; i < K; i++) {
            int X, Y;
            scanf("%d %d", &X, &Y);
            adj[X][Y] = 1;
            indegree[Y]++;
        }

        int W;
        scanf("%d", &W);

        int queue[MAX], front = 0, rear = 0;

        for (int i = 1; i <= N; i++) {
            dp[i] = D[i];
            if (indegree[i] == 0) queue[rear++] = i;
        }

        while (front < rear) {
            int now = queue[front++];

            for (int next = 1; next <= N; next++) {
                if (adj[now][next]) {
                    if (dp[next] < dp[now] + D[next]) {
                        dp[next] = dp[now] + D[next];
                    }
                    indegree[next]--;
                    if (indegree[next] == 0) queue[rear++] = next;
                }
            }
        }

        printf("%d\n", dp[W]);
    }

    return 0;
}