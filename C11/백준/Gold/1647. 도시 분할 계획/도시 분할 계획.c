#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a, b, cost;
} Edge;

int compare(const void* a, const void* b) {
    return ((Edge*)a)->cost - ((Edge*)b)->cost;
}

int parent[100005];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void union_sets(int a, int b) {
    a = find(a);
    b = find(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 1;

    Edge* edges = malloc(sizeof(Edge) * m);
    if (!edges) return 1;

    for (int i = 0; i < m; i++) {
        if (scanf("%d %d %d", &edges[i].a, &edges[i].b, &edges[i].cost) != 3)
            return 1;
        if (edges[i].a <= 0 || edges[i].a > n || edges[i].b <= 0 || edges[i].b > n)
            return 1;
    }

    for (int i = 1; i <= n; i++) parent[i] = i;

    qsort(edges, m, sizeof(Edge), compare);

    int total = 0;
    int maxCost = 0;

    for (int i = 0; i < m; i++) {
        if (find(edges[i].a) != find(edges[i].b)) {
            union_sets(edges[i].a, edges[i].b);
            total += edges[i].cost;
            if (edges[i].cost > maxCost) maxCost = edges[i].cost;
        }
    }

    printf("%d\n", total - maxCost);

    free(edges);
    return 0;
}