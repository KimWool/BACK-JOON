#include <stdio.h>

typedef long long ll;

ll countOnes(ll x) {
    ll count = 0;
    ll bit = 1;

    while (bit <= x) {
        ll totalPairs = x / (bit * 2);
        ll remainder = x % (bit * 2);

        count += totalPairs * bit;
        if (remainder >= bit) {
            count += remainder - bit + 1;
        }

        bit <<= 1;
    }

    return count;
}

int main() {
    ll A, B;
    scanf("%lld %lld", &A, &B);
    printf("%lld\n", countOnes(B) - countOnes(A - 1));
    return 0;
}