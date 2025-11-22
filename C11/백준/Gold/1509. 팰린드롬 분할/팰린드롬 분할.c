#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 2500

char str[MAX + 1];
bool isPalindrome[MAX][MAX];
int dp[MAX];

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    scanf("%s", str);
    int n = strlen(str);

    for (int i = 0; i < n; i++) {
        isPalindrome[i][i] = true;
    }

    for (int i = 0; i < n - 1; i++) {
        if (str[i] == str[i + 1]) {
            isPalindrome[i][i + 1] = true;
        }
    }

    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (str[i] == str[j] && isPalindrome[i + 1][j - 1]) {
                isPalindrome[i][j] = true;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        dp[i] = i + 1;
        for (int j = 0; j <= i; j++) {
            if (isPalindrome[j][i]) {
                if (j == 0) {
                    dp[i] = 1;
                } else {
                    dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
        }
    }

    printf("%d\n", dp[n - 1]);
    return 0;
}