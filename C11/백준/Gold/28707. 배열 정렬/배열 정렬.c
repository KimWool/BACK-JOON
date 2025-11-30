#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXQ 100000
#define NMAX 9
#define INF 1e9
#define HASH 131071

typedef struct {
    char state[NMAX];
    int cost;
} Node;

typedef struct VNode {
    struct VNode* next;
    char state[NMAX];
} VNode;

VNode* visited[HASH];
Node heap[MAXQ];
int heapSize = 0;

int N, M;
char target[NMAX];
int op[10][3];

int hash(char* s) {
    unsigned int h = 0;
    for (int i = 0; i < N; i++) {
        h = h * 131 + s[i];
    }
    return h % HASH;
}

int isVisited(char* s) {
    int h = hash(s);
    VNode* p = visited[h];
    while (p) {
        if (strncmp(p->state, s, N) == 0) return 1;
        p = p->next;
    }
    return 0;
}

void markVisited(char* s) {
    int h = hash(s);
    VNode* node = (VNode*)malloc(sizeof(VNode));
    strncpy(node->state, s, N);
    node->next = visited[h];
    visited[h] = node;
}

void swap(char* s, int a, int b) {
    char t = s[a];
    s[a] = s[b];
    s[b] = t;
}

void push(Node n) {
    heap[++heapSize] = n;
    int i = heapSize;
    while (i > 1 && heap[i].cost < heap[i / 2].cost) {
        Node tmp = heap[i];
        heap[i] = heap[i / 2];
        heap[i / 2] = tmp;
        i /= 2;
    }
}

Node pop() {
    Node top = heap[1];
    heap[1] = heap[heapSize--];
    int i = 1;
    while (1) {
        int min = i;
        if (i * 2 <= heapSize && heap[i * 2].cost < heap[min].cost) min = i * 2;
        if (i * 2 + 1 <= heapSize && heap[i * 2 + 1].cost < heap[min].cost) min = i * 2 + 1;
        if (min == i) break;
        Node tmp = heap[i];
        heap[i] = heap[min];
        heap[min] = tmp;
        i = min;
    }
    return top;
}

int cmp(const void* a, const void* b) {
    return *(char*)a - *(char*)b;
}

int main() {
    scanf("%d", &N);
    char start[NMAX];
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        start[i] = x + '0';
        target[i] = start[i];
    }

    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &op[i][0], &op[i][1], &op[i][2]);
        op[i][0]--;
        op[i][1]--;
    }

    qsort(target, N, sizeof(char), cmp);

    Node init;
    memcpy(init.state, start, N);
    init.cost = 0;
    push(init);

    while (heapSize > 0) {
        Node cur = pop();
        if (isVisited(cur.state)) continue;
        markVisited(cur.state);

        if (strncmp(cur.state, target, N) == 0) {
            printf("%d\n", cur.cost);
            return 0;
        }

        for (int i = 0; i < M; i++) {
            Node next;
            memcpy(next.state, cur.state, N);
            swap(next.state, op[i][0], op[i][1]);
            next.cost = cur.cost + op[i][2];

            if (!isVisited(next.state)) {
                push(next);
            }
        }
    }

    printf("-1\n");
    return 0;
}