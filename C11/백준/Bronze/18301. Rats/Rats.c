#include <stdio.h>
#include <math.h>

int main() {
    int n1, n2, n12;
    scanf("%d %d %d", &n1, &n2, &n12);

    int N = (int)floor((double)(n1 + 1) * (n2 + 1) / (n12 + 1) - 1);
    printf("%d", N);

    return 0;
}