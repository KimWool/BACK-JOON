#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void* a, const void* b) {
    long long val1 = *(long long*)a;
    long long val2 = *(long long*)b;
    if (val1 < val2) return -1;
    if (val1 > val2) return 1;
    return 0;
}

int main() {
    int N;
    scanf("%d", &N);
    long long arr[5000];
    for (int i = 0; i < N; i++) {
        scanf("%lld", &arr[i]);
    }

    qsort(arr, N, sizeof(long long), compare);

    long long min = 3000000001LL;
    long long x, y, z;

    for (int i = 0; i < N - 2; i++) {
        int left = i + 1;
        int right = N - 1;
        while (left < right) {
            long long sum = arr[i] + arr[left] + arr[right];
            if (llabs(sum) < min) {
                min = llabs(sum);
                x = arr[i];
                y = arr[left];
                z = arr[right];
            }
            if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    printf("%lld %lld %lld\n", x, y, z);
    return 0;
}