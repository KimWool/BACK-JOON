#include <stdio.h>
#include <stdlib.h>

#define MAX 100001

int N, K;
int dist[MAX];
int queue[MAX];
int front = 0, rear = 0;
int minTime = 1e9;
int count = 0;

void push(int x) {
    queue[rear++] = x;
}

int pop() {
    return queue[front++];
}

int empty() {
    return front == rear;
}

void bfs() {
    for (int i = 0; i < MAX; i++) dist[i] = -1;
    push(N);
    dist[N] = 0;

    while (!empty()) {
        int cur = pop();

        if (cur == K) {
            if (dist[cur] < minTime) {
                minTime = dist[cur];
                count = 1;
            } else if (dist[cur] == minTime) {
                count++;
            }
            continue;
        }

        int nexts[3] = {cur - 1, cur + 1, cur * 2};
        for (int i = 0; i < 3; i++) {
            int next = nexts[i];
            if (next < 0 || next >= MAX) continue;
            if (dist[next] == -1 || dist[next] == dist[cur] + 1) {
                dist[next] = dist[cur] + 1;
                push(next);
            }
        }
    }
}

int main() {
    scanf("%d %d", &N, &K);

    if (N >= K) {
        printf("%d\n1\n", N - K);
        return 0;
    }

    bfs();
    printf("%d\n%d\n", minTime, count);
    return 0;
}