#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int index, x, y, z;
} Planet;

typedef struct {
    int from, to, cost;
} Edge;

int compare_x(const void* a, const void* b) {
    return ((Planet*)a)->x - ((Planet*)b)->x;
}

int compare_y(const void* a, const void* b) {
    return ((Planet*)a)->y - ((Planet*)b)->y;
}

int compare_z(const void* a, const void* b) {
    return ((Planet*)a)->z - ((Planet*)b)->z;
}

int compare_edge(const void* a, const void* b) {
    return ((Edge*)a)->cost - ((Edge*)b)->cost;
}

int parent[100001];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b)
        parent[b] = a;
}

int abs_diff(int a, int b) {
    return a > b ? a - b : b - a;
}

int main() {
    int n;
    scanf("%d", &n);

    Planet* planets = (Planet*)malloc(sizeof(Planet) * n);
    Edge* edges = (Edge*)malloc(sizeof(Edge) * (3 * (n - 1)));
    int edge_cnt = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &planets[i].x, &planets[i].y, &planets[i].z);
        planets[i].index = i;
        parent[i] = i;
    }

    qsort(planets, n, sizeof(Planet), compare_x);
    for (int i = 0; i < n - 1; i++) {
        edges[edge_cnt].from = planets[i].index;
        edges[edge_cnt].to = planets[i + 1].index;
        edges[edge_cnt].cost = abs_diff(planets[i].x, planets[i + 1].x);
        edge_cnt++;
    }

    qsort(planets, n, sizeof(Planet), compare_y);
    for (int i = 0; i < n - 1; i++) {
        edges[edge_cnt].from = planets[i].index;
        edges[edge_cnt].to = planets[i + 1].index;
        edges[edge_cnt].cost = abs_diff(planets[i].y, planets[i + 1].y);
        edge_cnt++;
    }

    qsort(planets, n, sizeof(Planet), compare_z);
    for (int i = 0; i < n - 1; i++) {
        edges[edge_cnt].from = planets[i].index;
        edges[edge_cnt].to = planets[i + 1].index;
        edges[edge_cnt].cost = abs_diff(planets[i].z, planets[i + 1].z);
        edge_cnt++;
    }

    qsort(edges, edge_cnt, sizeof(Edge), compare_edge);

    int total_cost = 0;
    for (int i = 0; i < edge_cnt; i++) {
        if (find(edges[i].from) != find(edges[i].to)) {
            unite(edges[i].from, edges[i].to);
            total_cost += edges[i].cost;
        }
    }

    printf("%d\n", total_cost);

    free(planets);
    free(edges);
    return 0;
}