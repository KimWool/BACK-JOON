#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 102

typedef struct {
    int x, y;
} Point;

int h, w;
char map[MAX][MAX];
int visited[MAX][MAX];
int key[26];
Point door[26][MAX * MAX];
int doorCount[26];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

Point queue[MAX * MAX];
int front, rear;

void init() {
    memset(map, '.', sizeof(map));
    memset(visited, 0, sizeof(visited));
    memset(key, 0, sizeof(key));
    memset(doorCount, 0, sizeof(doorCount));
    front = rear = 0;
}

void enqueue(int x, int y) {
    queue[rear].x = x;
    queue[rear].y = y;
    rear++;
}

Point dequeue() {
    return queue[front++];
}

int bfs() {
    int result = 0;
    enqueue(0, 0);
    visited[0][0] = 1;

    while (front < rear) {
        Point cur = dequeue();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if (nx < 0 || ny < 0 || nx > h + 1 || ny > w + 1 || visited[nx][ny]) continue;
            char c = map[nx][ny];
            if (c == '*') continue;

            visited[nx][ny] = 1;

            if (c == '$') {
                result++;
                enqueue(nx, ny);
            } else if (c >= 'A' && c <= 'Z') {
                int idx = c - 'A';
                if (key[idx]) {
                    enqueue(nx, ny);
                } else {
                    door[idx][doorCount[idx]].x = nx;
                    door[idx][doorCount[idx]].y = ny;
                    doorCount[idx]++;
                }
            } else if (c >= 'a' && c <= 'z') {
                int idx = c - 'a';
                if (!key[idx]) {
                    key[idx] = 1;
                    enqueue(nx, ny);
                    for (int i = 0; i < doorCount[idx]; i++) {
                        Point p = door[idx][i];
                        enqueue(p.x, p.y);
                        visited[p.x][p.y] = 1;
                    }
                } else {
                    enqueue(nx, ny);
                }
            } else {
                enqueue(nx, ny);
            }
        }
    }

    return result;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        init();
        scanf("%d %d", &h, &w);
        getchar();

        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                map[i][j] = getchar();
            }
            getchar();
        }

        char keys[100];
        fgets(keys, sizeof(keys), stdin);
        if (keys[0] != '0') {
            for (int i = 0; keys[i]; i++) {
                if (keys[i] >= 'a' && keys[i] <= 'z') {
                    key[keys[i] - 'a'] = 1;
                }
            }
        }

        int ans = bfs();
        printf("%d\n", ans);
    }
    return 0;
}