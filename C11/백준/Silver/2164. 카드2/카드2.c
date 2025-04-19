#include <stdio.h>
#include <stdlib.h>

#define MAX 500000

typedef struct{
	int data[MAX];
	int front;
	int rear;
	int size;
} Queue;

void init(Queue* q) {
    q->front = q->rear = q->size = 0;
}

int isEmpty(Queue* q) {
    return q->size == 0;
}

int isFull(Queue* q) {
    return q->size == MAX;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        exit(1);
    }
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = value;
    q->size++;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        exit(1);
    }
    q->front = (q->front + 1) % MAX;
    q->size--;
    return q->data[q->front];
}

int main(void) {
    int N;
    scanf("%d", &N);

    Queue q;
    init(&q);

    for (int i = 1; i <= N; i++) {
        enqueue(&q, i);
    }

    while (q.size > 1) {
        dequeue(&q);
        enqueue(&q, dequeue(&q));
    }

    printf("%d", dequeue(&q));

    return 0;
}