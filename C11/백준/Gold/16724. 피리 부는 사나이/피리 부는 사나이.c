#include <stdio.h>

int n, m;
char map[1000][1001];
int visited[1000][1000];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int dir(char c) {
    if (c == 'D') return 0;
    if (c == 'U') return 1;
    if (c == 'R') return 2;
    if (c == 'L') return 3;
    return -1;
}

void dfs(int x, int y, int id, int* count) {
    visited[x][y] = id;
    int d = dir(map[x][y]);
    int nx = x + dx[d];
    int ny = y + dy[d];

    if (visited[nx][ny] == 0) {
        dfs(nx, ny, id, count);
    } else if (visited[nx][ny] == id) {
        (*count)++;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", map[i]);
    }

    int count = 0, id = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] == 0) {
                dfs(i, j, id++, &count);
            }
        }
    }

    printf("%d\n", count);
    return 0;
}