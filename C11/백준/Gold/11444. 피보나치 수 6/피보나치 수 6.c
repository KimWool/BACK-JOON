#include <stdio.h>

#define MOD 1000000007

typedef long long ll;

void multiply(ll a[2][2], ll b[2][2], ll res[2][2]) {
    res[0][0] = (a[0][0] * b[0][0] % MOD + a[0][1] * b[1][0] % MOD) % MOD;
    res[0][1] = (a[0][0] * b[0][1] % MOD + a[0][1] * b[1][1] % MOD) % MOD;
    res[1][0] = (a[1][0] * b[0][0] % MOD + a[1][1] * b[1][0] % MOD) % MOD;
    res[1][1] = (a[1][0] * b[0][1] % MOD + a[1][1] * b[1][1] % MOD) % MOD;
}

void power(ll n, ll result[2][2]) {
    ll base[2][2] = {{1, 1}, {1, 0}};
    ll temp[2][2] = {{1, 0}, {0, 1}};
    while (n > 0) {
        if (n % 2 == 1) {
            ll tmp[2][2];
            multiply(temp, base, tmp);
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++)
                    temp[i][j] = tmp[i][j];
        }
        ll tmp[2][2];
        multiply(base, base, tmp);
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                base[i][j] = tmp[i][j];
        n /= 2;
    }
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            result[i][j] = temp[i][j];
}

int main() {
    ll n;
    scanf("%lld", &n);
    ll result[2][2];
    power(n, result);
    printf("%lld\n", result[0][1]);
    return 0;
}