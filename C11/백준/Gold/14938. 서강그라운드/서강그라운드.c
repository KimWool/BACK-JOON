#include <stdio.h>
#define INF 1000000

int main() {
    int n, m, r;
    scanf("%d %d %d", &n, &m, &r);
    int t[101];
    for (int i = 1; i <= n; i++) scanf("%d", &t[i]);
    int dist[101][101];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dist[i][j] = (i == j) ? 0 : INF;
    for (int i = 0; i < r; i++) {
        int a, b, l;
        scanf("%d %d %d", &a, &b, &l);
        if (l < dist[a][b]) {
            dist[a][b] = l;
            dist[b][a] = l;
        }
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= n; j++)
            if (dist[i][j] <= m) sum += t[j];
        if (sum > ans) ans = sum;
    }
    printf("%d\n", ans);
    return 0;
}