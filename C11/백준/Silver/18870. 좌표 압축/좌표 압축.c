#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;
    return (x > y) - (x < y);
}

int binary_search(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    int N;
    scanf("%d", &N);
    
    int origin[N], sorted[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &origin[i]);
        sorted[i] = origin[i];
    }
    
    qsort(sorted, N, sizeof(int), compare);
    
    int unique[N], idx = 0;
    unique[idx++] = sorted[0];
    for (int i = 1; i < N; i++) {
        if (sorted[i] != sorted[i-1]) {
            unique[idx++] = sorted[i];
        }
    }

    for (int i = 0; i < N; i++) {
        int compressed = binary_search(unique, idx, origin[i]);
        printf("%d ", compressed);
    }

    return 0;
}