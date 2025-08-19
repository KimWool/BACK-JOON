#include<stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n / 2; i++) {
        printf("1 2");
        if (i != n / 2 - 1) {
            printf(" ");
        }
    }

    if (n % 2 != 0) {
        printf(" 3");
    }

    return 0;
}