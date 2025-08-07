#include <stdio.h>
#include <math.h>

int main() {
    int A, B;
    scanf("%d %d", &A, &B);

    double M = (double)(B - A) / 400.0;
    double result = 1.0 / (1.0 + pow(10.0, M));

    printf("%lf", result);

    return 0;
}