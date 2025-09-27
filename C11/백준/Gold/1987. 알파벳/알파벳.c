#include <stdio.h>
#include <stdbool.h>

int R, C;
char board[20][21]; 
bool visited[26];
int max = 0;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y, int count) {
    if (count > max) max = count;
    visited[board[x][y] - 'A'] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < R && ny < C) {
            if (!visited[board[nx][ny] - 'A']) {
                dfs(nx, ny, count + 1);
            }
        }
    }

    visited[board[x][y] - 'A'] = false;
}

int main() {
    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; i++) {
        scanf("%s", board[i]);
    }

    dfs(0, 0, 1);
    printf("%d\n", max);

    return 0;
}