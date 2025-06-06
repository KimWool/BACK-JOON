#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100001

int heap[MAX];
int size = 0;

int compare(int a, int b) {
    int absA = abs(a);
    int absB = abs(b);
    if (absA == absB) return a - b;
    return absA - absB;
}

void swap(int *a, int *b) {
    int temp = *a; *a = *b; *b = temp;
}

void push(int x) {
    int i = ++size;
    heap[i] = x;

    while (i > 1 && compare(heap[i], heap[i / 2]) < 0) {
        swap(&heap[i], &heap[i / 2]);
        i /= 2;
    }
}

int pop() {
    if (size == 0) return 0;

    int top = heap[1];
    heap[1] = heap[size--];

    int i = 1;
    while (1) {
        int left = i * 2;
        int right = i * 2 + 1;
        int smallest = i;

        if (left <= size && compare(heap[left], heap[smallest]) < 0)
            smallest = left;
        if (right <= size && compare(heap[right], heap[smallest]) < 0)
            smallest = right;

        if (smallest == i) break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }

    return top;
}

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        int x;
        scanf("%d", &x);
        if (x == 0) {
            printf("%d\n", pop());
        } else {
            push(x);
        }
    }

    return 0;
}