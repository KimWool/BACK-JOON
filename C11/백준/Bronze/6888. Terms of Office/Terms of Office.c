#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int X, Y;
    scanf("%d", &X);
    scanf("%d", &Y);

    int interval = lcm(4, lcm(2, lcm(3, 5)));

    for (int year = X; year <= Y; year++) {
        if ((year - X) % interval == 0) {
            printf("All positions change in year %d\n", year);
        }
    }

    return 0;
}