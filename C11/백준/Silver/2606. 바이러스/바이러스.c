#include <stdio.h>

int graph[101][101];
int visited[101];
int count = 0;

void dfs(int start, int node) {
    visited[start] = 1;

    for (int i = 1; i <= node; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            count++;
            dfs(i, node);
        }
    }
}

int main() {
    int node, edge;
    scanf("%d", &node);
    scanf("%d", &edge);

    for (int i = 0; i < edge; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    dfs(1, node);
    printf("%d", count);

    return 0;
}