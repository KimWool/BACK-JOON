#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int index;
    int priority;
} Document;

typedef struct Node {
    Document doc;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int size;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = NULL;
    q->size = 0;
}

int isEmpty(Queue* q) {
    return q->size == 0;
}

void push(Queue* q, Document doc) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->doc = doc;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    q->size++;
}

Document pop(Queue* q) {
    Node* temp = q->front;
    Document result = temp->doc;

    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    q->size--;
    return result;
}

int hasHigherPriority(Queue* q, int priority) {
    Node* current = q->front;
    while (current != NULL) {
        if (current->doc.priority > priority)
            return 1;
        current = current->next;
    }
    return 0;
}

int main(void) {
    int testCases;
    scanf("%d", &testCases);

    while (testCases--) {
        int N, M;
        scanf("%d %d", &N, &M);

        Queue q;
        initQueue(&q);

        for (int i = 0; i < N; i++) {
            int p;
            scanf("%d", &p);
            Document doc = {i, p};
            push(&q, doc);
        }

        int printCount = 0;
        while (!isEmpty(&q)) {
            Document cur = pop(&q);

            if (hasHigherPriority(&q, cur.priority)) {
                push(&q, cur);
            } else {
                printCount++;
                if (cur.index == M) {
                    printf("%d\n", printCount);
                    break;
                }
            }
        }
    }

    return 0;
}