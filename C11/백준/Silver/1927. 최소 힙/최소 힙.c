#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100000

typedef struct {
    int data[MAX_SIZE];
    int size;
} PriorityQueue;

bool isEmpty(PriorityQueue* pq) {
    return pq->size == 0;
}

void offer(PriorityQueue* pq, int value) {
    int i = pq->size++;
    pq->data[i] = value;

    while (i > 0) {
        int parent = (i - 1) / 2;
        if (pq->data[parent] <= pq->data[i]) break;

        int temp = pq->data[parent];
        pq->data[parent] = pq->data[i];
        pq->data[i] = temp;

        i = parent;
    }
}

int poll(PriorityQueue* pq) {
    if (isEmpty(pq)) return 0;

    int minValue = pq->data[0];
    pq->data[0] = pq->data[--pq->size];

    int i = 0;
    while (true) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < pq->size && pq->data[left] < pq->data[smallest]) {
            smallest = left;
        }
        if (right < pq->size && pq->data[right] < pq->data[smallest]) {
            smallest = right;
        }
        if (smallest == i) break;

        int temp = pq->data[i];
        pq->data[i] = pq->data[smallest];
        pq->data[smallest] = temp;

        i = smallest;
    }

    return minValue;
}

int main(void) {
	
	int N;
	scanf("%d", &N);
	
	PriorityQueue pq;
	pq.size = 0;
	
	for(int i = 0; i < N; i++) {
		int input;
		scanf("%d", &input);
		
		if(input == 0) {
			if(isEmpty(&pq)) {
				printf("%d\n", 0);
			} else {
				printf("%d\n", poll(&pq));
			}
		} else {
			offer(&pq, input);
		}
	}
	
	return 0;
}