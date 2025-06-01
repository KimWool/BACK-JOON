#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int dist[MAX];
int queue[MAX];
int front, rear;

int N, M;

void init_queue() {
    front = rear = 0;
}

int is_empty() {
    return front == rear;
}

void enqueue(int x) {
    queue[rear++] = x;
}

int dequeue() {
    return queue[front++];
}

int bfs(int start) {
    memset(visited, 0, sizeof(visited));
    memset(dist, 0, sizeof(dist));
    init_queue();

    visited[start] = 1;
    enqueue(start);

    while (!is_empty()) {
        int curr = dequeue();
        for (int i = 0; i < N; i++) {
            if (adj[curr][i] && !visited[i]) {
                visited[i] = 1;
                dist[i] = dist[curr] + 1;
                enqueue(i);
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += dist[i];
    }
    return sum;
}

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int minSum = 1e9;
    int result = -1;

    for (int i = 0; i < N; i++) {
        int sum = bfs(i);
        if (sum < minSum) {
            minSum = sum;
            result = i;
        }
    }

    printf("%d\n", result + 1);
    return 0;
}