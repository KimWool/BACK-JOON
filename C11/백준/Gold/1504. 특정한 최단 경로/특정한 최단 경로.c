#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 200000000

typedef struct {
    int vertex;
    int cost;
    struct Node* next;
} Node;

typedef struct {
    int vertex;
    int dist;
} HeapNode;

typedef struct {
    HeapNode* data;
    int size;
} MinHeap;

int N, E;
Node* graph[801];

MinHeap* createHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->data = (HeapNode*)malloc(sizeof(HeapNode) * (capacity + 1));
    heap->size = 0;
    return heap;
}

void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void push(MinHeap* heap, int vertex, int dist) {
    heap->size++;
    int idx = heap->size;
    heap->data[idx].vertex = vertex;
    heap->data[idx].dist = dist;

    while (idx > 1 && heap->data[idx].dist < heap->data[idx / 2].dist) {
        swap(&heap->data[idx], &heap->data[idx / 2]);
        idx /= 2;
    }
}

HeapNode pop(MinHeap* heap) {
    HeapNode top = heap->data[1];
    heap->data[1] = heap->data[heap->size];
    heap->size--;

    int idx = 1;
    while (1) {
        int left = idx * 2;
        int right = idx * 2 + 1;
        int smallest = idx;

        if (left <= heap->size && heap->data[left].dist < heap->data[smallest].dist)
            smallest = left;
        if (right <= heap->size && heap->data[right].dist < heap->data[smallest].dist)
            smallest = right;

        if (smallest == idx) break;

        swap(&heap->data[idx], &heap->data[smallest]);
        idx = smallest;
    }

    return top;
}

int dijkstra(int start, int end) {
    int* dist = (int*)malloc(sizeof(int) * (N + 1));
    for (int i = 1; i <= N; i++) dist[i] = INF;
    dist[start] = 0;

    MinHeap* heap = createHeap(N * N);
    push(heap, start, 0);

    while (heap->size > 0) {
        HeapNode now = pop(heap);
        int v = now.vertex;
        int d = now.dist;

        if (d > dist[v]) continue;

        for (Node* cur = graph[v]; cur != NULL; cur = cur->next) {
            int next = cur->vertex;
            int cost = d + cur->cost;
            if (cost < dist[next]) {
                dist[next] = cost;
                push(heap, next, cost);
            }
        }
    }

    int result = dist[end];
    free(dist);
    free(heap->data);
    free(heap);
    return result;
}

void addEdge(int a, int b, int c) {
    Node* newNode1 = (Node*)malloc(sizeof(Node));
    newNode1->vertex = b;
    newNode1->cost = c;
    newNode1->next = graph[a];
    graph[a] = newNode1;

    Node* newNode2 = (Node*)malloc(sizeof(Node));
    newNode2->vertex = a;
    newNode2->cost = c;
    newNode2->next = graph[b];
    graph[b] = newNode2;
}

int main() {
    scanf("%d %d", &N, &E);

    for (int i = 0; i < E; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        addEdge(a, b, c);
    }

    int v1, v2;
    scanf("%d %d", &v1, &v2);

    long long route1 = 0;
    route1 += dijkstra(1, v1);
    route1 += dijkstra(v1, v2);
    route1 += dijkstra(v2, N);

    long long route2 = 0;
    route2 += dijkstra(1, v2);
    route2 += dijkstra(v2, v1);
    route2 += dijkstra(v1, N);

    long long answer = (route1 >= INF && route2 >= INF) ? -1 : (route1 < route2 ? route1 : route2);

    printf("%lld\n", answer);
    return 0;
}