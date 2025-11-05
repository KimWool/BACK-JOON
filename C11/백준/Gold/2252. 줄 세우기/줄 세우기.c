#include <stdio.h>
#include <stdlib.h>

#define MAX 32001

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int indegree[MAX];
Node* graph[MAX];
int queue[MAX];
int front = 0, rear = 0;

void addEdge(int from, int to) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = to;
    newNode->next = graph[from];
    graph[from] = newNode;
    indegree[to]++;
}

void enqueue(int x) {
    queue[rear++] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++) {
        int A, B;
        scanf("%d %d", &A, &B);
        addEdge(A, B);
    }

    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    while (!isEmpty()) {
        int curr = dequeue();
        printf("%d ", curr);

        Node* temp = graph[curr];
        while (temp != NULL) {
            indegree[temp->data]--;
            if (indegree[temp->data] == 0) {
                enqueue(temp->data);
            }
            temp = temp->next;
        }
    }

    return 0;
}