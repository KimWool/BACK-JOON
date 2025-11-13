#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int m;
    int v;
} Jewel;

int compare_jewel(const void* a, const void* b) {
    return ((Jewel*)a)->m - ((Jewel*)b)->m;
}

int compare_int(const void* a, const void* b) {
    return (*(int*)a) - (*(int*)b);
}

typedef struct {
    int* data;
    int size;
} MaxHeap;

void heap_init(MaxHeap* h, int capacity) {
    h->data = (int*)malloc(sizeof(int) * (capacity + 1));
    h->size = 0;
}

void heap_push(MaxHeap* h, int value) {
    int i = ++h->size;
    while (i > 1 && h->data[i / 2] < value) {
        h->data[i] = h->data[i / 2];
        i /= 2;
    }
    h->data[i] = value;
}

int heap_pop(MaxHeap* h) {
    int max = h->data[1];
    int temp = h->data[h->size--];
    int parent = 1, child = 2;
    while (child <= h->size) {
        if (child < h->size && h->data[child] < h->data[child + 1]) child++;
        if (temp >= h->data[child]) break;
        h->data[parent] = h->data[child];
        parent = child;
        child *= 2;
    }
    h->data[parent] = temp;
    return max;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    Jewel* jewels = (Jewel*)malloc(sizeof(Jewel) * N);
    int* c = (int*)malloc(sizeof(int) * K);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &jewels[i].m, &jewels[i].v);
    }
    for (int i = 0; i < K; i++) {
        scanf("%d", &c[i]);
    }

    qsort(jewels, N, sizeof(Jewel), compare_jewel);
    qsort(c, K, sizeof(int), compare_int);

    MaxHeap heap;
    heap_init(&heap, N);

    long long result = 0;
    int j = 0;

    for (int i = 0; i < K; i++) {
        while (j < N && jewels[j].m <= c[i]) {
            heap_push(&heap, jewels[j].v);
            j++;
        }
        if (heap.size > 0) {
            result += heap_pop(&heap);
        }
    }

    printf("%lld\n", result);

    free(jewels);
    free(c);
    free(heap.data);
    return 0;
}