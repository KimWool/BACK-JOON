#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int to;
    int cost;
    int next;
} Edge;

typedef struct {
    int v;
    int dist;
} Node;

typedef struct {
    Node *heap;
    int size;
} PriorityQueue;

int compare(Node a, Node b) {
    return a.dist < b.dist;
}

void push(PriorityQueue *pq, Node n) {
    int i = ++pq->size;
    while (i > 1 && pq->heap[i/2].dist > n.dist) {
        pq->heap[i] = pq->heap[i/2];
        i /= 2;
    }
    pq->heap[i] = n;
}

Node pop(PriorityQueue *pq) {
    Node ret = pq->heap[1];
    Node temp = pq->heap[pq->size--];
    int parent = 1, child = 2;
    while (child <= pq->size) {
        if (child < pq->size && pq->heap[child].dist > pq->heap[child+1].dist) child++;
        if (temp.dist <= pq->heap[child].dist) break;
        pq->heap[parent] = pq->heap[child];
        parent = child;
        child *= 2;
    }
    pq->heap[parent] = temp;
    return ret;
}

int main() {
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);

    Edge *edges = (Edge*)malloc(sizeof(Edge) * (M + 1));
    int *head = (int*)malloc(sizeof(int) * (N + 1));
    for (int i = 1; i <= N; i++) head[i] = -1;

    for (int i = 0; i < M; i++) {
        int from, to, cost;
        scanf("%d %d %d", &from, &to, &cost);
        edges[i].to = to;
        edges[i].cost = cost;
        edges[i].next = head[from];
        head[from] = i;
    }

    int A, B;
    scanf("%d %d", &A, &B);

    int *dist = (int*)malloc(sizeof(int) * (N + 1));
    for (int i = 1; i <= N; i++) dist[i] = INT_MAX;
    dist[A] = 0;

    PriorityQueue pq;
    pq.heap = (Node*)malloc(sizeof(Node) * (M + 2));
    pq.size = 0;

    push(&pq, (Node){A, 0});

    while (pq.size > 0) {
        Node cur = pop(&pq);
        if (cur.dist > dist[cur.v]) continue;
        for (int i = head[cur.v]; i != -1; i = edges[i].next) {
            int next = edges[i].to;
            int ncost = cur.dist + edges[i].cost;
            if (dist[next] > ncost) {
                dist[next] = ncost;
                push(&pq, (Node){next, ncost});
            }
        }
    }

    printf("%d\n", dist[B]);

    free(edges);
    free(head);
    free(dist);
    free(pq.heap);
    return 0;
}