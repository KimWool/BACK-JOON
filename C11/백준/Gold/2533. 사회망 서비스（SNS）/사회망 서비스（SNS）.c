#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000001

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* tree[MAX];
int dp[MAX][2];
int visited[MAX];

void add_edge(int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = tree[u];
    tree[u] = newNode;
}

int min(int a, int b) {
    return a < b ? a : b;
}

void dfs(int node) {
    visited[node] = 1;
    dp[node][0] = 0;
    dp[node][1] = 1;

    Node* curr = tree[node];
    while (curr != NULL) {
        int child = curr->vertex;
        if (!visited[child]) {
            dfs(child);
            dp[node][0] += dp[child][1];
            dp[node][1] += min(dp[child][0], dp[child][1]);
        }
        curr = curr->next;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }

    dfs(1);

    printf("%d\n", min(dp[1][0], dp[1][1]));
    return 0;
}