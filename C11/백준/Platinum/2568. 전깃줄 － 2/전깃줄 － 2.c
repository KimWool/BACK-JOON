#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a, b;
} Wire;

int compare(const void* x, const void* y) {
    return ((Wire*)x)->a - ((Wire*)y)->a;
}

int lower_bound(int* arr, int size, int target) {
    int left = 0, right = size;
    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int main() {
    int n;
    scanf("%d", &n);

    Wire* wires = (Wire*)malloc(sizeof(Wire) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &wires[i].a, &wires[i].b);
    }

    qsort(wires, n, sizeof(Wire), compare);

    int* dp = (int*)malloc(sizeof(int) * n);
    int* idxArr = (int*)malloc(sizeof(int) * n);
    int* prev = (int*)malloc(sizeof(int) * n);
    int* pos = (int*)malloc(sizeof(int) * n);
    int len = 0;

    for (int i = 0; i < n; i++) {
        int b = wires[i].b;
        int idx = lower_bound(dp, len, b);
        dp[idx] = b;
        pos[idx] = i;
        prev[i] = (idx > 0) ? pos[idx - 1] : -1;
        idxArr[i] = idx;
        if (idx == len) len++;
    }

    int* isInLIS = (int*)calloc(n, sizeof(int));
    int trace = -1;
    for (int i = 0; i < n; i++) {
        if (idxArr[i] == len - 1) {
            trace = i;
            break;
        }
    }

    while (trace != -1) {
        isInLIS[trace] = 1;
        trace = prev[trace];
    }

    int* removed = (int*)malloc(sizeof(int) * n);
    int removedCount = 0;
    for (int i = 0; i < n; i++) {
        if (!isInLIS[i])
            removed[removedCount++] = wires[i].a;
    }

    qsort(removed, removedCount, sizeof(int), compare);

    printf("%d\n", removedCount);
    for (int i = 0; i < removedCount; i++) {
        printf("%d\n", removed[i]);
    }

    free(wires);
    free(dp);
    free(idxArr);
    free(prev);
    free(pos);
    free(isInLIS);
    free(removed);

    return 0;
}