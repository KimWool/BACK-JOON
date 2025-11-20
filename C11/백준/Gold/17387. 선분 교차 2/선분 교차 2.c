#include <stdio.h>

typedef struct {
    long long x, y;
} Point;

int ccw(Point a, Point b, Point c) {
    long long op = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (op > 0) return 1;
    if (op < 0) return -1;
    return 0;
}

int in_range(long long a, long long b, long long c) {
    if (a > b) {
        long long tmp = a;
        a = b;
        b = tmp;
    }
    return a <= c && c <= b;
}

int isOverlapping(Point a, Point b, Point c, Point d) {
    if (a.x > b.x || (a.x == b.x && a.y > b.y)) {
        Point tmp = a; a = b; b = tmp;
    }
    if (c.x > d.x || (c.x == d.x && c.y > d.y)) {
        Point tmp = c; c = d; d = tmp;
    }
    return !(b.x < c.x || d.x < a.x || b.y < c.y || d.y < a.y);
}

int main() {
    Point a, b, c, d;
    scanf("%lld %lld %lld %lld", &a.x, &a.y, &b.x, &b.y);
    scanf("%lld %lld %lld %lld", &c.x, &c.y, &d.x, &d.y);

    int ab_c = ccw(a, b, c);
    int ab_d = ccw(a, b, d);
    int cd_a = ccw(c, d, a);
    int cd_b = ccw(c, d, b);

    if (ab_c * ab_d == 0 && cd_a * cd_b == 0) {
        if (
            in_range(a.x, b.x, c.x) || in_range(a.x, b.x, d.x) ||
            in_range(c.x, d.x, a.x) || in_range(c.x, d.x, b.x)
        ) {
            if (
                in_range(a.y, b.y, c.y) || in_range(a.y, b.y, d.y) ||
                in_range(c.y, d.y, a.y) || in_range(c.y, d.y, b.y)
            ) {
                printf("1\n");
                return 0;
            }
        }
        printf("0\n");
    } else {
        if (ab_c * ab_d <= 0 && cd_a * cd_b <= 0)
            printf("1\n");
        else
            printf("0\n");
    }

    return 0;
}