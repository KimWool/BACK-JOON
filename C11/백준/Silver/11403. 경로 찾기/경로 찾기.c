#include <stdio.h>
#include <string.h>

#define MAX 100

int N;
int graph[MAX][MAX];
int result[MAX][MAX];
int visited[MAX];

void dfs(int start, int curr) {
    for (int next = 0; next < N; next++) {
        if (graph[curr][next] == 1 && !visited[next]) {
            visited[next] = 1;
            result[start][next] = 1;
            dfs(start, next);
        }
    }
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        memset(visited, 0, sizeof(visited));
        dfs(i, i);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}