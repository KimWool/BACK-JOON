#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

typedef struct Queue{
    Node* front;
    Node* back;
    int size;
} Queue;

void initQueue(Queue* q){
    q->front = q->back = NULL;
    q->size = 0;
}

void push(Queue* q, int data){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (q->back == NULL){
        q->front = q->back = newNode;
    } else{
        q->back->next = newNode;
        q->back = newNode;
    }
    q->size++;
}

int pop(Queue* q){
    if (q->front == NULL) return -1;

    Node* temp = q->front;
    int result = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) q->back = NULL;
    free(temp);
    q->size--;
    return result;
}

int getSize(Queue* q){
    return q->size;
}

int isEmpty(Queue* q){
    return q->size == 0 ? 1 : 0;
}

int getFront(Queue* q){
    if (q->front == NULL) return -1;
    return q->front->data;
}

int getBack(Queue* q){
    if (q->back == NULL) return -1;
    return q->back->data;
}

int main(){
    int N;
    scanf("%d", &N);
    getchar();

    Queue q;
    initQueue(&q);

    char command[20];

    for (int i = 0; i < N; i++){
        fgets(command, sizeof(command), stdin);

        if (strncmp(command, "push", 4) == 0){
            int x;
            sscanf(command + 5, "%d", &x);
            push(&q, x);
        } else if (strncmp(command, "pop", 3) == 0){
            printf("%d\n", pop(&q));
        } else if (strncmp(command, "size", 4) == 0){
            printf("%d\n", getSize(&q));
        } else if (strncmp(command, "empty", 5) == 0){
            printf("%d\n", isEmpty(&q));
        } else if (strncmp(command, "front", 5) == 0){
            printf("%d\n", getFront(&q));
        } else if (strncmp(command, "back", 4) == 0){
            printf("%d\n", getBack(&q));
        }
    }

    return 0;
}