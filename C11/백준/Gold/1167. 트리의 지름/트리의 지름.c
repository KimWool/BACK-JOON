#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int to;
    int cost;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} List;

List* tree;
int* visited;
int max = 0;
int node;

void addEdge(int from, int to, int cost) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->to = to;
    newNode->cost = cost;
    newNode->next = tree[from].head;
    tree[from].head = newNode;
}

void dfs(int x, int len) {
    if (len > max) {
        max = len;
        node = x;
    }
    visited[x] = 1;
    Node* cur = tree[x].head;
    while (cur != NULL) {
        if (!visited[cur->to]) {
            dfs(cur->to, len + cur->cost);
        }
        cur = cur->next;
    }
}

int main() {
    int V;
    scanf("%d", &V);

    tree = (List*)malloc(sizeof(List) * (V + 1));
    visited = (int*)calloc(V + 1, sizeof(int));

    for (int i = 1; i <= V; i++) {
        tree[i].head = NULL;
    }

    for (int i = 0; i < V; i++) {
        int from;
        scanf("%d", &from);
        while (1) {
            int to, cost;
            scanf("%d", &to);
            if (to == -1) break;
            scanf("%d", &cost);
            addEdge(from, to, cost);
        }
    }

    dfs(1, 0);

    for (int i = 0; i <= V; i++) visited[i] = 0;

    dfs(node, 0);

    printf("%d\n", max);

    for (int i = 1; i <= V; i++) {
        Node* cur = tree[i].head;
        while (cur != NULL) {
            Node* tmp = cur;
            cur = cur->next;
            free(tmp);
        }
    }

    free(tree);
    free(visited);

    return 0;
}