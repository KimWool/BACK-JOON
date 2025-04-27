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

int isEmpty(Queue* q){
    return q->size == 0 ? 1 : 0;
}

int main(){
    
    int N, K;
    scanf("%d %d", &N, &K);
    
    Queue q;
    initQueue(&q);
    for(int i = 1; i <= N; i++){
    	push(&q, i);
	}
	
	int index = 1;
	printf("<");
	
	while(!isEmpty(&q)){
		if(index % K == 0){
			printf("%d", pop(&q));
			if(!isEmpty(&q)){
				printf(", ");
			}
		} else{
			push(&q, pop(&q));
		}
		index++;
	}
	
	printf(">");

    return 0;
}