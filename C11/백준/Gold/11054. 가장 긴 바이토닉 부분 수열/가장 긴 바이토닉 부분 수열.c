#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int A[1001];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int dp_inc[1001] = {0};
    int dp_dec[1001] = {0};

    for (int i = 0; i < N; i++) {
        dp_inc[i] = 1;
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i] && dp_inc[j] + 1 > dp_inc[i]) {
                dp_inc[i] = dp_inc[j] + 1;
            }
        }
    }

    for (int i = N - 1; i >= 0; i--) {
        dp_dec[i] = 1;
        for (int j = N - 1; j > i; j--) {
            if (A[j] < A[i] && dp_dec[j] + 1 > dp_dec[i]) {
                dp_dec[i] = dp_dec[j] + 1;
            }
        }
    }

    int result = 0;
    for (int i = 0; i < N; i++) {
        int len = dp_inc[i] + dp_dec[i] - 1;
        if (len > result) result = len;
    }

    printf("%d\n", result);
    return 0;
}