#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

typedef struct {
    ll x, y;
} Point;

typedef struct {
    Point p1, p2;
} Line;

int* parent;
int* count;

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int a, int b) {
    int ra = find(a);
    int rb = find(b);
    if (ra != rb) {
        parent[rb] = ra;
        count[ra] += count[rb];
    }
}

int ccw(Point a, Point b, Point c) {
    ll op = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (op > 0) return 1;
    if (op < 0) return -1;
    return 0;
}

int is_cross(Line l1, Line l2) {
    Point a = l1.p1, b = l1.p2, c = l2.p1, d = l2.p2;

    int ab = ccw(a, b, c) * ccw(a, b, d);
    int cd = ccw(c, d, a) * ccw(c, d, b);

    if (ab == 0 && cd == 0) {
        if (a.x > b.x) { Point tmp = a; a = b; b = tmp; }
        if (c.x > d.x) { Point tmp = c; c = d; d = tmp; }
        if (b.x < c.x || d.x < a.x) return 0;
        if (a.y > b.y) { Point tmp = a; a = b; b = tmp; }
        if (c.y > d.y) { Point tmp = c; c = d; d = tmp; }
        if (b.y < c.y || d.y < a.y) return 0;
        return 1;
    }

    return ab <= 0 && cd <= 0;
}

int main() {
    int n;
    scanf("%d", &n);

    Line* lines = (Line*)malloc(sizeof(Line) * n);
    parent = (int*)malloc(sizeof(int) * n);
    count = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        ll x1, y1, x2, y2;
        scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
        lines[i].p1.x = x1;
        lines[i].p1.y = y1;
        lines[i].p2.x = x2;
        lines[i].p2.y = y2;
        parent[i] = i;
        count[i] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (is_cross(lines[i], lines[j])) {
                unite(i, j);
            }
        }
    }

    int group_count = 0;
    int max_group_size = 0;

    for (int i = 0; i < n; i++) {
        if (parent[i] == i) {
            group_count++;
            if (count[i] > max_group_size)
                max_group_size = count[i];
        }
    }

    printf("%d\n%d\n", group_count, max_group_size);

    free(lines);
    free(parent);
    free(count);

    return 0;
}