#include <stdio.h>

int parent[100001];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void union_set(int a, int b) {
    a = find(a);
    b = find(b);
    parent[a] = b;
}

int main() {
    int G, P, gi, result = 0;
    scanf("%d", &G);
    scanf("%d", &P);

    for (int i = 0; i <= G; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < P; i++) {
        scanf("%d", &gi);
        int root = find(gi);
        if (root == 0)
            break;
        union_set(root, root - 1);
        result++;
    }

    printf("%d\n", result);
    return 0;
}