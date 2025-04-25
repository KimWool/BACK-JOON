#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

typedef struct {
    int data[MAX];
    int top;
} Stack;

void push(Stack *s, int value) {
    if (s->top < MAX - 1) {
        s->data[++(s->top)] = value;
    }
}

int pop(Stack *s) {
    if (s->top == -1) return -1;
    return s->data[(s->top)--];
}

int size(Stack *s) {
    return s->top + 1;
}

int empty(Stack *s) {
    return (s->top == -1) ? 1 : 0;
}

int top(Stack *s) {
    if (s->top == -1) return -1;
    return s->data[s->top];
}

int main(void){
	
	int N;
	scanf("%d", &N);
	
	Stack stack;
	stack.top = -1;
	
	for(int i = 0; i < N; i++){
		char command[10];
		int number;
		scanf("%s", command);

        if (strcmp(command, "push") == 0){
			scanf("%d", &number);
            push(&stack, number);
        } else if (strcmp(command, "pop") == 0){
            printf("%d\n", pop(&stack));
        } else if (strcmp(command, "size") == 0){
            printf("%d\n", size(&stack));
        } else if (strcmp(command, "empty") == 0){
            printf("%d\n", empty(&stack));
        } else if (strcmp(command, "top") == 0){
            printf("%d\n", top(&stack));
        }
	}
	
	return 0;
}