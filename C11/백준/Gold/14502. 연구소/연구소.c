#include <stdio.h>
#include <stdlib.h>

int N, M;
int map[8][8];
int copy[8][8];
int max = 0;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

typedef struct {
    int x, y;
} Point;

Point queue[64];
int front, rear;

void copyMap() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            copy[i][j] = map[i][j];
}

void bfs() {
    front = rear = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (copy[i][j] == 2)
                queue[rear++] = (Point){i, j};

    while (front < rear) {
        Point now = queue[front++];
        for (int k = 0; k < 4; k++) {
            int nx = now.x + dx[k];
            int ny = now.y + dy[k];
            if (nx >= 0 && ny >= 0 && nx < N && ny < M)
                if (copy[nx][ny] == 0) {
                    copy[nx][ny] = 2;
                    queue[rear++] = (Point){nx, ny};
                }
        }
    }
}

int countSafeZone() {
    int cnt = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (copy[i][j] == 0)
                cnt++;
    return cnt;
}

void dfs(int count) {
    if (count == 3) {
        copyMap();
        bfs();
        int safe = countSafeZone();
        if (safe > max) max = safe;
        return;
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (map[i][j] == 0) {
                map[i][j] = 1;
                dfs(count + 1);
                map[i][j] = 0;
            }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", &map[i][j]);
    dfs(0);
    printf("%d\n", max);
    return 0;
}