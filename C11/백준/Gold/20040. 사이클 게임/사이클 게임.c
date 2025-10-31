#include <stdio.h>

int parent[500000];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void union_set(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px != py) {
        parent[py] = px;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    int result = 0;
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (find(a) == find(b)) {
            result = i;
            break;
        } else {
            union_set(a, b);
        }
    }

    printf("%d\n", result);
    return 0;
}