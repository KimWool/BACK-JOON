#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 101

int ladder[MAX];
int snake[MAX];
int visited[MAX];
int moves[MAX];

typedef struct {
    int position;
} QueueNode;

typedef struct {
    QueueNode data[MAX * 10];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = 0;
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, int pos) {
    q->data[q->rear++].position = pos;
}

int dequeue(Queue* q) {
    return q->data[q->front++].position;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        ladder[x] = y;
    }

    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        snake[u] = v;
    }

    Queue q;
    initQueue(&q);

    enqueue(&q, 1);
    visited[1] = 1;
    moves[1] = 0;

    while (!isEmpty(&q)) {
        int current = dequeue(&q);

        if (current == 100) {
            printf("%d\n", moves[current]);
            break;
        }

        for (int i = 1; i <= 6; i++) {
            int next = current + i;
            if (next > 100) continue;

            if (ladder[next]) {
                next = ladder[next];
            } else if (snake[next]) {
                next = snake[next];
            }

            if (!visited[next]) {
                visited[next] = 1;
                moves[next] = moves[current] + 1;
                enqueue(&q, next);
            }
        }
    }

    return 0;
}