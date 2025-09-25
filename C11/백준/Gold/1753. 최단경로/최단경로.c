#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Edge {
    int v, w;
    struct Edge* next;
} Edge;

typedef struct {
    int v, dist;
} Node;

typedef struct {
    Node *heap;
    int size;
} MinHeap;

Edge* graph[20001];
int dist[20001];
int V, E, K;

MinHeap* createHeap(int n) {
    MinHeap* h = (MinHeap*)malloc(sizeof(MinHeap));
    h->heap = (Node*)malloc(sizeof(Node) * (n + 1));
    h->size = 0;
    return h;
}

void push(MinHeap* h, int v, int dist) {
    h->heap[++h->size].v = v;
    h->heap[h->size].dist = dist;
    int i = h->size;
    while (i > 1 && h->heap[i].dist < h->heap[i/2].dist) {
        Node tmp = h->heap[i];
        h->heap[i] = h->heap[i/2];
        h->heap[i/2] = tmp;
        i /= 2;
    }
}

Node pop(MinHeap* h) {
    Node top = h->heap[1];
    h->heap[1] = h->heap[h->size--];
    int i = 1;
    while (1) {
        int left = i * 2, right = i * 2 + 1, smallest = i;
        if (left <= h->size && h->heap[left].dist < h->heap[smallest].dist) smallest = left;
        if (right <= h->size && h->heap[right].dist < h->heap[smallest].dist) smallest = right;
        if (smallest == i) break;
        Node tmp = h->heap[i];
        h->heap[i] = h->heap[smallest];
        h->heap[smallest] = tmp;
        i = smallest;
    }
    return top;
}

void addEdge(int u, int v, int w) {
    Edge* e = (Edge*)malloc(sizeof(Edge));
    e->v = v;
    e->w = w;
    e->next = graph[u];
    graph[u] = e;
}

int main() {
    scanf("%d %d", &V, &E);
    scanf("%d", &K);

    for (int i = 1; i <= V; i++) {
        graph[i] = NULL;
        dist[i] = INT_MAX;
    }

    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    MinHeap* pq = createHeap(E + 1);
    dist[K] = 0;
    push(pq, K, 0);

    while (pq->size > 0) {
        Node cur = pop(pq);
        if (dist[cur.v] < cur.dist) continue;
        for (Edge* e = graph[cur.v]; e != NULL; e = e->next) {
            int next = e->v;
            int cost = e->w;
            if (dist[next] > cur.dist + cost) {
                dist[next] = cur.dist + cost;
                push(pq, next, dist[next]);
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (dist[i] == INT_MAX) printf("INF\n");
        else printf("%d\n", dist[i]);
    }

    return 0;
}