#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Person;

int compare(const void* a, const void* b) {
    Person* p1 = (Person*)a;
    Person* p2 = (Person*)b;
    return p1->end - p2->end;
}

void heapify_up(int* heap, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (heap[parent] <= heap[idx]) break;
        int temp = heap[parent];
        heap[parent] = heap[idx];
        heap[idx] = temp;
        idx = parent;
    }
}

void heapify_down(int* heap, int* size) {
    int idx = 0;
    while (1) {
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        int smallest = idx;

        if (left < *size && heap[left] < heap[smallest])
            smallest = left;
        if (right < *size && heap[right] < heap[smallest])
            smallest = right;
        if (smallest == idx) break;

        int temp = heap[smallest];
        heap[smallest] = heap[idx];
        heap[idx] = temp;
        idx = smallest;
    }
}

void insert_heap(int* heap, int* size, int value) {
    heap[(*size)++] = value;
    heapify_up(heap, *size - 1);
}

void remove_heap(int* heap, int* size) {
    if (*size == 0) return;
    heap[0] = heap[--(*size)];
    heapify_down(heap, size);
}

int main() {
    int n;
    scanf("%d", &n);
    Person* people = malloc(sizeof(Person) * n);

    for (int i = 0; i < n; i++) {
        int h, o;
        scanf("%d %d", &h, &o);
        people[i].start = h < o ? h : o;
        people[i].end = h > o ? h : o;
    }

    int d;
    scanf("%d", &d);

    Person* valid = malloc(sizeof(Person) * n);
    int valid_count = 0;

    for (int i = 0; i < n; i++) {
        if (people[i].end - people[i].start <= d) {
            valid[valid_count++] = people[i];
        }
    }

    qsort(valid, valid_count, sizeof(Person), compare);

    int* heap = malloc(sizeof(int) * valid_count);
    int heap_size = 0;
    int max_count = 0;

    for (int i = 0; i < valid_count; i++) {
        int range_start = valid[i].end - d;
        insert_heap(heap, &heap_size, valid[i].start);

        while (heap_size > 0 && heap[0] < range_start) {
            remove_heap(heap, &heap_size);
        }

        if (heap_size > max_count) max_count = heap_size;
    }

    printf("%d\n", max_count);

    free(people);
    free(valid);
    free(heap);
    return 0;
}