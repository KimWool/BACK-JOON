#include <stdio.h>
#include <stdlib.h>

#define MAX 32001

typedef struct Node {
    int to;
    struct Node* next;
} Node;

Node* adj[MAX];
int indegree[MAX];

typedef struct {
    int heap[MAX];
    int size;
} MinHeap;

void push(MinHeap* h, int value) {
    int i = ++(h->size);
    while (i != 1 && value < h->heap[i / 2]) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = value;
}

int pop(MinHeap* h) {
    int min = h->heap[1];
    int temp = h->heap[h->size--];
    int parent = 1, child = 2;
    while (child <= h->size) {
        if (child < h->size && h->heap[child] > h->heap[child + 1]) child++;
        if (temp <= h->heap[child]) break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return min;
}

void addEdge(int from, int to) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->to = to;
    newNode->next = adj[from];
    adj[from] = newNode;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++) {
        int A, B;
        scanf("%d %d", &A, &B);
        addEdge(A, B);
        indegree[B]++;
    }

    MinHeap heap = { .size = 0 };
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0)
            push(&heap, i);
    }

    while (heap.size > 0) {
        int current = pop(&heap);
        printf("%d ", current);
        Node* cur = adj[current];
        while (cur) {
            int next = cur->to;
            indegree[next]--;
            if (indegree[next] == 0)
                push(&heap, next);
            cur = cur->next;
        }
    }

    return 0;
}