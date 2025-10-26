#include <stdio.h>
#define INF 1000001

int main() {
    int n, s;
    scanf("%d %d", &n, &s);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0, start = 0, end = 0, minLength = INF;

    while (1) {
        if (sum >= s) {
            if (end - start < minLength)
                minLength = end - start;
            sum -= arr[start++];
        } else if (end == n) {
            break;
        } else {
            sum += arr[end++];
        }
    }

    if (minLength == INF)
        printf("0\n");
    else
        printf("%d\n", minLength);

    return 0;
}