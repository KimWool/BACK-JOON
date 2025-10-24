#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int A, B, C;
} Edge;

int parent[10001];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void union_set(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    if (rootA != rootB) parent[rootB] = rootA;
}

int compare(const void* a, const void* b) {
    return ((Edge*)a)->C - ((Edge*)b)->C;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    Edge edges[100000];
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].A, &edges[i].B, &edges[i].C);
    }

    for (int i = 1; i <= V; i++) parent[i] = i;

    qsort(edges, E, sizeof(Edge), compare);

    int result = 0;
    for (int i = 0; i < E; i++) {
        if (find(edges[i].A) != find(edges[i].B)) {
            union_set(edges[i].A, edges[i].B);
            result += edges[i].C;
        }
    }

    printf("%d\n", result);
    return 0;
}