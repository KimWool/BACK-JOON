#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int A[1000], dp[1000];
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);

    for (int i = 0; i < N; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    int result = 0;
    for (int i = 0; i < N; i++) {
        if (dp[i] > result) result = dp[i];
    }

    printf("%d\n", result);
    return 0;
}