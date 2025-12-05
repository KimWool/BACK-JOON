#include <stdio.h>
#include <string.h>

#define MOD 1000000007
#define SIZE 8

typedef long long ll;
ll base[SIZE][SIZE] = {
    {0,1,1,0,0,0,0,0},
    {1,0,1,1,0,0,0,0},
    {1,1,0,1,1,0,0,0},
    {0,1,1,0,1,1,0,0},
    {0,0,1,1,0,1,1,0},
    {0,0,0,1,1,0,0,1},
    {0,0,0,0,1,0,0,1},
    {0,0,0,0,0,1,1,0}
};

void multiply(ll a[SIZE][SIZE], ll b[SIZE][SIZE], ll result[SIZE][SIZE]) {
    ll temp[SIZE][SIZE] = {0};
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                temp[i][j] = (temp[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    memcpy(result, temp, sizeof(temp));
}

void power(ll matrix[SIZE][SIZE], int exp, ll result[SIZE][SIZE]) {
    ll temp[SIZE][SIZE];
    memcpy(result, matrix, sizeof(base));
    exp--;

    while (exp > 0) {
        if (exp % 2 == 1) {
            memcpy(temp, result, sizeof(temp));
            multiply(temp, matrix, result);
        }
        multiply(matrix, matrix, matrix);
        exp /= 2;
    }
}

int main() {
    int D;
    scanf("%d", &D);

    ll result[SIZE][SIZE];
    power(base, D, result);

    printf("%lld\n", result[0][0]);
    return 0;
}