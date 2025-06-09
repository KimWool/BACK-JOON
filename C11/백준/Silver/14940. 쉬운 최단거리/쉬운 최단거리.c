#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000
int map[MAX][MAX];
int dist[MAX][MAX];
int visited[MAX][MAX];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

typedef struct {
    int x, y;
} Point;

Point queue[MAX * MAX];
int front = 0, rear = 0;

void enqueue(int x, int y) {
    queue[rear].x = x;
    queue[rear].y = y;
    rear++;
}

Point dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

void bfs(int startX, int startY, int n, int m) {
    enqueue(startX, startY);
    visited[startX][startY] = 1;
    dist[startX][startY] = 0;

    while (!isEmpty()) {
        Point cur = dequeue();
        int cx = cur.x;
        int cy = cur.y;

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if (!visited[nx][ny] && map[nx][ny] == 1) {
                    visited[nx][ny] = 1;
                    dist[nx][ny] = dist[cx][cy] + 1;
                    enqueue(nx, ny);
                }
            }
        }
    }
}

int main() {
    int n, m, startX = 0, startY = 0;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 2) {
                startX = i;
                startY = j;
            }
        }
    }

    bfs(startX, startY, n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0) {
                printf("0 ");
            } else if (!visited[i][j]) {
                printf("-1 ");
            } else {
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}