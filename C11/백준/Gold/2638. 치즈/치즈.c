#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N, M;
int map[100][100];
int visited[100][100];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

typedef struct {
    int x, y;
} Point;

Point queue[10000];
int front, rear;

void bfs_air() {
    memset(visited, 0, sizeof(visited));
    front = rear = 0;
    queue[rear++] = (Point){0, 0};
    visited[0][0] = 1;
    while (front < rear) {
        Point cur = queue[front++];
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (visited[nx][ny] || map[nx][ny] == 1) continue;
            visited[nx][ny] = 1;
            queue[rear++] = (Point){nx, ny};
        }
    }
}

int melt() {
    int meltList[100][100];
    int meltCount = 0;
    memset(meltList, 0, sizeof(meltList));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 1) {
                int cnt = 0;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                    if (visited[nx][ny]) cnt++;
                }
                if (cnt >= 2) {
                    meltList[i][j] = 1;
                    meltCount++;
                }
            }
        }
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (meltList[i][j]) map[i][j] = 0;
    return meltCount;
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", &map[i][j]);

    int time = 0;
    while (1) {
        bfs_air();
        int melted = melt();
        if (melted == 0) break;
        time++;
    }
    printf("%d\n", time);
    return 0;
}