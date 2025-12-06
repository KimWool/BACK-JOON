#include <stdio.h>
#include <stdlib.h>

int lower_bound(int* arr, int size, int target) {
    int left = 0, right = size;
    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    return right;
}

int main() {
    int N;
    scanf("%d", &N);

    int* A = (int*)malloc(sizeof(int) * N);
    int* dp = (int*)malloc(sizeof(int) * N);
    int* index = (int*)malloc(sizeof(int) * N);
    int* result = (int*)malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int length = 0;

    for (int i = 0; i < N; i++) {
        int pos = lower_bound(dp, length, A[i]);
        dp[pos] = A[i];
        index[i] = pos;
        if (pos == length) length++;
    }

    int cur = length - 1;
    for (int i = N - 1; i >= 0; i--) {
        if (index[i] == cur) {
            result[cur] = A[i];
            cur--;
        }
    }

    printf("%d\n", length);
    for (int i = 0; i < length; i++) {
        printf("%d ", result[i]);
    }

    free(A);
    free(dp);
    free(index);
    free(result);

    return 0;
}