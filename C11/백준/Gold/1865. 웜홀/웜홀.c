#include <stdio.h>
#include <stdlib.h>
#define INF 1000000000

typedef struct {
    int from, to, cost;
} Edge;

int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        int N, M, W;
        scanf("%d %d %d", &N, &M, &W);
        int edgeCount = M * 2 + W;
        Edge* edges = (Edge*)malloc(sizeof(Edge) * edgeCount);
        int idx = 0;
        for (int i = 0; i < M; i++) {
            int S, E, T;
            scanf("%d %d %d", &S, &E, &T);
            edges[idx].from = S; edges[idx].to = E; edges[idx++].cost = T;
            edges[idx].from = E; edges[idx].to = S; edges[idx++].cost = T;
        }
        for (int i = 0; i < W; i++) {
            int S, E, T;
            scanf("%d %d %d", &S, &E, &T);
            edges[idx].from = S; edges[idx].to = E; edges[idx++].cost = -T;
        }

        int* dist = (int*)malloc(sizeof(int) * (N + 1));
        for (int i = 1; i <= N; i++) dist[i] = 0;
        int updated = 0;

        for (int i = 1; i <= N; i++) {
            updated = 0;
            for (int j = 0; j < edgeCount; j++) {
                int u = edges[j].from;
                int v = edges[j].to;
                int w = edges[j].cost;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    updated = 1;
                    if (i == N) {
                        printf("YES\n");
                        free(edges);
                        free(dist);
                        goto next_case;
                    }
                }
            }
            if (!updated) break;
        }
        printf("NO\n");
        free(edges);
        free(dist);
        next_case:;
    }
    return 0;
}