#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x, y, dist;
} Node;

int n;
int space[20][20];
int visited[20][20];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int sharkSize = 2, eatCount = 0, timeSpent = 0;
int sharkX, sharkY;

int compare(const void *a, const void *b) {
    Node *n1 = (Node *)a;
    Node *n2 = (Node *)b;
    if (n1->dist != n2->dist) return n1->dist - n2->dist;
    if (n1->x != n2->x) return n1->x - n2->x;
    return n1->y - n2->y;
}

Node bfs() {
    Node queue[400];
    int front = 0, rear = 0;
    Node fishes[400];
    int fishCount = 0;
    int minDist = 1e9;

    memset(visited, 0, sizeof(visited));
    queue[rear++] = (Node){sharkX, sharkY, 0};
    visited[sharkX][sharkY] = 1;

    while (front < rear) {
        Node cur = queue[front++];
        if (cur.dist > minDist) break;
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (visited[nx][ny] || space[nx][ny] > sharkSize) continue;
            visited[nx][ny] = 1;
            if (space[nx][ny] && space[nx][ny] < sharkSize) {
                fishes[fishCount++] = (Node){nx, ny, cur.dist + 1};
                minDist = cur.dist + 1;
            }
            queue[rear++] = (Node){nx, ny, cur.dist + 1};
        }
    }

    if (fishCount == 0) return (Node){-1, -1, -1};
    qsort(fishes, fishCount, sizeof(Node), compare);
    return fishes[0];
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &space[i][j]);
            if (space[i][j] == 9) {
                sharkX = i;
                sharkY = j;
                space[i][j] = 0;
            }
        }
    }

    while (1) {
        Node target = bfs();
        if (target.x == -1) break;
        timeSpent += target.dist;
        sharkX = target.x;
        sharkY = target.y;
        space[target.x][target.y] = 0;
        eatCount++;
        if (eatCount == sharkSize) {
            sharkSize++;
            eatCount = 0;
        }
    }

    printf("%d\n", timeSpent);
    return 0;
}