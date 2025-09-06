#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int to;
    struct Node* next;
} Node;

Node* graph[100001];
int parent[100001];
int visited[100001];
int N;

void add_edge(int a, int b) {
    Node* n1 = (Node*)malloc(sizeof(Node));
    n1->to = b;
    n1->next = graph[a];
    graph[a] = n1;
}

void dfs(int node) {
    visited[node] = 1;
    for (Node* cur = graph[node]; cur; cur = cur->next) {
        if (!visited[cur->to]) {
            parent[cur->to] = node;
            dfs(cur->to);
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        add_edge(a, b);
        add_edge(b, a);
    }
    dfs(1);
    for (int i = 2; i <= N; i++) {
        printf("%d\n", parent[i]);
    }
    return 0;
}