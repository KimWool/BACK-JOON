#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int to;
    int weight;
    struct Node* next;
} Node;

Node* tree[10001];
int visited[10001];
int farNode, maxDist;

void addEdge(int from, int to, int weight) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->to = to;
    newNode->weight = weight;
    newNode->next = tree[from];
    tree[from] = newNode;
}

void dfs(int node, int dist) {
    visited[node] = 1;
    if (dist > maxDist) {
        maxDist = dist;
        farNode = node;
    }
    for (Node* cur = tree[node]; cur != NULL; cur = cur->next) {
        if (!visited[cur->to]) {
            dfs(cur->to, dist + cur->weight);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i <= n; i++) {
        tree[i] = NULL;
    }

    for (int i = 0; i < n - 1; i++) {
        int parent, child, weight;
        scanf("%d %d %d", &parent, &child, &weight);
        addEdge(parent, child, weight);
        addEdge(child, parent, weight);
    }

    if (n == 1) {
        printf("0\n");
        return 0;
    }

    memset(visited, 0, sizeof(visited));
    maxDist = 0;
    dfs(1, 0);

    memset(visited, 0, sizeof(visited));
    maxDist = 0;
    dfs(farNode, 0);

    printf("%d\n", maxDist);
    return 0;
}