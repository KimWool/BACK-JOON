#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 1000000000

typedef struct {
    int end;
    int cost;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} List;

typedef struct {
    int vertex;
    int dist;
} HeapNode;

typedef struct {
    HeapNode* heap;
    int size;
} MinHeap;

int N, M, X;
List* graph;
List* reverseGraph;

void addEdge(List* g, int start, int end, int cost) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->end = end;
    newNode->cost = cost;
    newNode->next = g[start].head;
    g[start].head = newNode;
}

MinHeap* createHeap(int n) {
    MinHeap* h = (MinHeap*)malloc(sizeof(MinHeap));
    h->heap = (HeapNode*)malloc(sizeof(HeapNode) * (n + 1));
    h->size = 0;
    return h;
}

void push(MinHeap* h, int v, int d) {
    int i = ++h->size;
    while (i != 1 && d < h->heap[i / 2].dist) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i].vertex = v;
    h->heap[i].dist = d;
}

HeapNode pop(MinHeap* h) {
    HeapNode root = h->heap[1];
    HeapNode temp = h->heap[h->size--];
    int parent = 1, child = 2;
    while (child <= h->size) {
        if (child < h->size && h->heap[child].dist > h->heap[child + 1].dist) child++;
        if (temp.dist <= h->heap[child].dist) break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return root;
}

int isEmpty(MinHeap* h) {
    return h->size == 0;
}

int* dijkstra(List* g, int start) {
    int* dist = (int*)malloc(sizeof(int) * (N + 1));
    for (int i = 1; i <= N; i++) dist[i] = INF;
    MinHeap* pq = createHeap(N);
    dist[start] = 0;
    push(pq, start, 0);
    while (!isEmpty(pq)) {
        HeapNode now = pop(pq);
        if (now.dist > dist[now.vertex]) continue;
        for (Node* tmp = g[now.vertex].head; tmp; tmp = tmp->next) {
            int next = tmp->end;
            int nd = now.dist + tmp->cost;
            if (nd < dist[next]) {
                dist[next] = nd;
                push(pq, next, nd);
            }
        }
    }
    return dist;
}

int main() {
    scanf("%d %d %d", &N, &M, &X);
    graph = (List*)malloc(sizeof(List) * (N + 1));
    reverseGraph = (List*)malloc(sizeof(List) * (N + 1));
    for (int i = 1; i <= N; i++) {
        graph[i].head = NULL;
        reverseGraph[i].head = NULL;
    }
    for (int i = 0; i < M; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        addEdge(graph, a, b, c);
        addEdge(reverseGraph, b, a, c);
    }

    int* go = dijkstra(graph, X);
    int* back = dijkstra(reverseGraph, X);

    int maxTime = 0;
    for (int i = 1; i <= N; i++) {
        if (go[i] == INF || back[i] == INF) continue;
        int total = go[i] + back[i];
        if (total > maxTime) maxTime = total;
    }

    printf("%d\n", maxTime);
    return 0;
}