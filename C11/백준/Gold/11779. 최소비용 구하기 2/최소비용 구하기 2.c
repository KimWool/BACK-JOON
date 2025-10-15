#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct { int v, cost, next; } Edge;
typedef struct { int v, cost; } HeapNode;

Edge edges[100001];
int head[1001];
int edgeCount = 0;
HeapNode heap[100001];
int heapSize = 0;

void addEdge(int a, int b, int c) {
    edges[++edgeCount].v = b;
    edges[edgeCount].cost = c;
    edges[edgeCount].next = head[a];
    head[a] = edgeCount;
}

void swap(HeapNode* a, HeapNode* b) { HeapNode t = *a; *a = *b; *b = t; }

void push(HeapNode x) {
    heap[++heapSize] = x;
    for (int i = heapSize; i > 1 && heap[i].cost < heap[i/2].cost; i /= 2)
        swap(&heap[i], &heap[i/2]);
}

HeapNode pop() {
    HeapNode top = heap[1];
    heap[1] = heap[heapSize--];
    int i = 1;
    while (1) {
        int l = i*2, r = i*2+1, s = i;
        if (l <= heapSize && heap[l].cost < heap[s].cost) s = l;
        if (r <= heapSize && heap[r].cost < heap[s].cost) s = r;
        if (s == i) break;
        swap(&heap[i], &heap[s]);
        i = s;
    }
    return top;
}

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    for (int i = 1; i <= n; i++) head[i] = 0;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        addEdge(a, b, c);
    }

    int start, end;
    scanf("%d %d", &start, &end);

    int dist[1001], prev[1001], visited[1001] = {0};
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        prev[i] = 0;
    }
    dist[start] = 0;
    push((HeapNode){start, 0});

    while (heapSize > 0) {
        HeapNode cur = pop();
        int v = cur.v;
        if (visited[v]) continue;
        visited[v] = 1;
        for (int e = head[v]; e; e = edges[e].next) {
            int nv = edges[e].v;
            int nc = edges[e].cost;
            if (dist[nv] > dist[v] + nc) {
                dist[nv] = dist[v] + nc;
                prev[nv] = v;
                push((HeapNode){nv, dist[nv]});
            }
        }
    }

    printf("%d\n", dist[end]);
    int path[1001], count = 0;
    for (int v = end; v != 0; v = prev[v]) path[count++] = v;
    printf("%d\n", count);
    for (int i = count - 1; i >= 0; i--) printf("%d ", path[i]);
}