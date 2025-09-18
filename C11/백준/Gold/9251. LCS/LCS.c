#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    char A[1001], B[1001];
    scanf("%s", A);
    scanf("%s", B);

    int n = strlen(A);
    int m = strlen(B);

    int dp[1001][1001] = {0};

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    printf("%d\n", dp[n][m]);
    return 0;
}