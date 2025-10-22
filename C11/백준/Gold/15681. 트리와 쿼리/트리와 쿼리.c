#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100001

int N, R, Q;
int subtree[MAX];
bool visited[MAX];

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* tree[MAX];

void addEdge(int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = tree[u];
    tree[u] = newNode;
}

int dfs(int node) {
    visited[node] = true;
    subtree[node] = 1;

    Node* curr = tree[node];
    while (curr != NULL) {
        int next = curr->vertex;
        if (!visited[next]) {
            subtree[node] += dfs(next);
        }
        curr = curr->next;
    }

    return subtree[node];
}

int main() {
    scanf("%d %d %d", &N, &R, &Q);

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }

    dfs(R);

    for (int i = 0; i < Q; i++) {
        int query;
        scanf("%d", &query);
        printf("%d\n", subtree[query]);
    }

    return 0;
}