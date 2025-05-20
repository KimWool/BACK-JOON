#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1001

int graph[MAX][MAX];
bool visited[MAX];
int queue[MAX];
int front = 0, rear = 0;

void dfs(int v, int n) {
    visited[v] = true;
    printf("%d ", v);

    for (int i = 1; i <= n; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            dfs(i, n);
        }
    }
}

void bfs(int v, int n) {
    front = rear = 0;
    for (int i = 0; i < MAX; i++) visited[i] = false;

    queue[rear++] = v;
    visited[v] = true;

    while (front < rear) {
        int cur = queue[front++];
        printf("%d ", cur);

        for (int i = 1; i <= n; i++) {
            if (graph[cur][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = true;
            }
        }
    }
}

int main() {
    int n, m, v;
    scanf("%d %d %d", &n, &m, &v);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    dfs(v, n);
    printf("\n");

    for (int i = 0; i < MAX; i++) visited[i] = false;
    bfs(v, n);

    return 0;
}