#include <stdio.h>

int N;
int map[17][17];
int count = 0;

void dfs(int r, int c, int dir) {
    if (r == N - 1 && c == N - 1) {
        count++;
        return;
    }

    if (dir == 0 || dir == 2) {
        if (c + 1 < N && map[r][c + 1] == 0) {
            dfs(r, c + 1, 0);
        }
    }

    if (dir == 1 || dir == 2) {
        if (r + 1 < N && map[r + 1][c] == 0) {
            dfs(r + 1, c, 1);
        }
    }

    if (r + 1 < N && c + 1 < N) {
        if (map[r][c + 1] == 0 && map[r + 1][c] == 0 && map[r + 1][c + 1] == 0) {
            dfs(r + 1, c + 1, 2);
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    dfs(0, 1, 0);
    printf("%d\n", count);

    return 0;
}