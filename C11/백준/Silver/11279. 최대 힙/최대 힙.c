#include <stdio.h>

#define MAX_SIZE 100001

int heap[MAX_SIZE];
int size = 0;

void insert(int x) {
    int i = ++size;
    while (i != 1 && x > heap[i / 2]) {
        heap[i] = heap[i / 2];
        i /= 2;
    }
    heap[i] = x;
}

int delete() {
    if (size == 0) return 0;

    int max = heap[1];
    int temp = heap[size--];
    int parent = 1, child = 2;

    while (child <= size) {
        if (child < size && heap[child] < heap[child + 1]) child++;
        if (temp >= heap[child]) break;

        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }
    heap[parent] = temp;
    return max;
}

int main() {
    int N, x;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        if (x == 0) {
            printf("%d\n", delete());
        } else {
            insert(x);
        }
    }

    return 0;
}