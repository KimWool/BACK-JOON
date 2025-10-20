#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);

    long long x[10000], y[10000];
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &x[i], &y[i]);
    }

    double area = 0;
    for (int i = 0; i < n; i++) {
        area += (x[i] * y[(i + 1) % n]) - (x[(i + 1) % n] * y[i]);
    }

    area = fabs(area) / 2.0;
    printf("%.1f\n", area);

    return 0;
}