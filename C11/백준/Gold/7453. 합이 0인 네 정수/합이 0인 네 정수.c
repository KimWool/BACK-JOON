#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;
    return (x > y) - (x < y);
}

int lower_bound(int *arr, int size, int target) {
    int left = 0, right = size;
    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid] < target) left = mid + 1;
        else right = mid;
    }
    return left;
}

int upper_bound(int *arr, int size, int target) {
    int left = 0, right = size;
    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid] <= target) left = mid + 1;
        else right = mid;
    }
    return left;
}

int main() {
    int n;
    scanf("%d", &n);

    int *A = malloc(n * sizeof(int));
    int *B = malloc(n * sizeof(int));
    int *C = malloc(n * sizeof(int));
    int *D = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
    }

    int size = n * n;
    int *AB = malloc(size * sizeof(int));
    int *CD = malloc(size * sizeof(int));

    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            AB[idx] = A[i] + B[j];
            CD[idx] = C[i] + D[j];
            idx++;
        }
    }

    qsort(CD, size, sizeof(int), compare);

    long long count = 0;
    for (int i = 0; i < size; i++) {
        int target = -AB[i];
        int lower = lower_bound(CD, size, target);
        int upper = upper_bound(CD, size, target);
        count += (upper - lower);
    }

    printf("%lld\n", count);

    free(A);
    free(B);
    free(C);
    free(D);
    free(AB);
    free(CD);
    return 0;
}