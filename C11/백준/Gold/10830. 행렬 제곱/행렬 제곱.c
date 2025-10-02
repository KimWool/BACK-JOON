#include <stdio.h>

#define MOD 1000
#define MAX 5

int N;
long long B;
int A[MAX][MAX];

void multiply(int a[MAX][MAX], int b[MAX][MAX], int res[MAX][MAX]) {
    int temp[MAX][MAX] = {0};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            long long sum = 0;
            for (int k = 0; k < N; k++) {
                sum += (long long)a[i][k] * b[k][j];
            }
            temp[i][j] = sum % MOD;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            res[i][j] = temp[i][j];
        }
    }
}

void power(int base[MAX][MAX], long long exp, int result[MAX][MAX]) {
    if (exp == 1) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                result[i][j] = base[i][j] % MOD;
            }
        }
        return;
    }

    int half[MAX][MAX];
    power(base, exp / 2, half);

    int temp[MAX][MAX];
    multiply(half, half, temp);

    if (exp % 2 == 0) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                result[i][j] = temp[i][j];
            }
        }
    } else {
        multiply(temp, A, result);
    }
}

int main() {
    scanf("%d %lld", &N, &B);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
            A[i][j] %= MOD;
        }
    }

    int result[MAX][MAX];
    power(A, B, result);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", result[i][j] % MOD);
        }
        printf("\n");
    }
    return 0;
}