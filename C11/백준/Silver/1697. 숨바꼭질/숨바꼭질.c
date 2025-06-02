#include <stdio.h>
#include <stdbool.h>

#define MAX 100001

int queue[MAX];
int time[MAX];
bool visited[MAX];
int front = 0, rear = 0;

void enqueue(int x) {
    queue[rear++] = x;
}

int dequeue() {
    return queue[front++];
}

int bfs(int start, int target) {
    enqueue(start);
    visited[start] = true;
    time[start] = 0;

    while (front < rear) {
        int now = dequeue();

        if (now == target) return time[now];

        int next[3] = {now - 1, now + 1, now * 2};
        for (int i = 0; i < 3; i++) {
            int nx = next[i];
            if (nx >= 0 && nx < MAX && !visited[nx]) {
                enqueue(nx);
                visited[nx] = true;
                time[nx] = time[now] + 1;
            }
        }
    }
    return -1;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int result = bfs(N, K);
    printf("%d\n", result);

    return 0;
}