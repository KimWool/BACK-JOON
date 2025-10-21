#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, N, sizeof(int), compare);

    int left = 0;
    int right = N - 1;
    int min_sum = INT_MAX;
    int answer1 = 0, answer2 = 0;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (abs(sum) < min_sum) {
            min_sum = abs(sum);
            answer1 = arr[left];
            answer2 = arr[right];
        }

        if (sum < 0) {
            left++;
        } else {
            right--;
        }
    }

    printf("%d %d\n", answer1, answer2);
    return 0;
}