#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y, dist, broken;
} Node;

int N, M;
int map[1001][1001];
int visited[2][1001][1001];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

typedef struct {
    Node data[2000000];
    int front, rear;
} Queue;

void initQueue(Queue* q) { q->front = q->rear = 0; }
int isEmpty(Queue* q) { return q->front == q->rear; }
void enqueue(Queue* q, Node n) { q->data[q->rear++] = n; }
Node dequeue(Queue* q) { return q->data[q->front++]; }

int bfs() {
    Queue q;
    initQueue(&q);
    Node start = {0, 0, 1, 0};
    enqueue(&q, start);
    visited[0][0][0] = 1;

    while (!isEmpty(&q)) {
        Node cur = dequeue(&q);
        if (cur.x == N - 1 && cur.y == M - 1) return cur.dist;

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

            if (map[nx][ny] == 0 && !visited[cur.broken][nx][ny]) {
                visited[cur.broken][nx][ny] = 1;
                Node next = {nx, ny, cur.dist + 1, cur.broken};
                enqueue(&q, next);
            } else if (map[nx][ny] == 1 && cur.broken == 0 && !visited[1][nx][ny]) {
                visited[1][nx][ny] = 1;
                Node next = {nx, ny, cur.dist + 1, 1};
                enqueue(&q, next);
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        char line[1001];
        scanf("%s", line);
        for (int j = 0; j < M; j++) {
            map[i][j] = line[j] - '0';
        }
    }

    printf("%d\n", bfs());
    return 0;
}