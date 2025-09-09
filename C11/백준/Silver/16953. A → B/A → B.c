#include <stdio.h>

int main() {
    long long A, B;
    scanf("%lld %lld", &A, &B);

    int count = 1;

    while (B > A) {
        if (B % 2 == 0) {
            B /= 2;
        } else if (B % 10 == 1) {
            B /= 10;
        } else {
            break;
        }
        count++;
    }

    if (B == A) {
        printf("%d", count);
    } else {
        printf("-1");
    }

    return 0;
}