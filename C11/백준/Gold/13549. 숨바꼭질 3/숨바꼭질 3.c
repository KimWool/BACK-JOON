#include <stdio.h>
#include <string.h>

#define MAX 100000

int N, K;
int dist[MAX + 1];
int deque[MAX * 2 + 1];
int front, rear;

void push_front(int x) {
    deque[--front] = x;
}

void push_back(int x) {
    deque[rear++] = x;
}

int pop_front() {
    return deque[front++];
}

int empty() {
    return front == rear;
}

int main() {
    scanf("%d %d", &N, &K);

    memset(dist, -1, sizeof(dist));

    front = rear = MAX; // 덱의 중간에서 시작
    push_back(N);
    dist[N] = 0;

    while (!empty()) {
        int x = pop_front();
        if (x == K) {
            printf("%d\n", dist[x]);
            return 0;
        }

        int nx = x * 2;
        if (nx <= MAX && dist[nx] == -1) {
            dist[nx] = dist[x];
            push_front(nx);
        }

        nx = x - 1;
        if (nx >= 0 && dist[nx] == -1) {
            dist[nx] = dist[x] + 1;
            push_back(nx);
        }

        nx = x + 1;
        if (nx <= MAX && dist[nx] == -1) {
            dist[nx] = dist[x] + 1;
            push_back(nx);
        }
    }

    return 0;
}