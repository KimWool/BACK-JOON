#include <stdio.h>

int lower_bound(int* arr, int size, int target) {
    int left = 0;
    int right = size;
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
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int lis[n];
    int length = 0;

    for (int i = 0; i < n; i++) {
        int pos = lower_bound(lis, length, a[i]);
        lis[pos] = a[i];
        if (pos == length)
            length++;
    }

    printf("%d\n", length);
    return 0;
}