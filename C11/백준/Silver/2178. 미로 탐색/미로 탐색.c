#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int N, M;
int map[MAX][MAX];
int visited[MAX][MAX];
int dist[MAX][MAX];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

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

int is_empty() {
    return front == rear;
}

int bfs(int x, int y) {
    enqueue(x, y);
    visited[x][y] = 1;
    dist[x][y] = 1;

    while (!is_empty()) {
        Point p = dequeue();
        int cx = p.x;
        int cy = p.y;

        if (cx == N - 1 && cy == M - 1) {
            return dist[cx][cy];
        }

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
                if (!visited[nx][ny] && map[nx][ny] == 1) {
                    visited[nx][ny] = 1;
                    dist[nx][ny] = dist[cx][cy] + 1;
                    enqueue(nx, ny);
                }
            }
        }
    }

    return 0;
}

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        char line[MAX];
        scanf("%s", line);
        for (int j = 0; j < M; j++) {
            map[i][j] = line[j] - '0';
        }
    }

    int result = bfs(0, 0);
    printf("%d\n", result);

    return 0;
}