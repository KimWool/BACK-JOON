#include <stdio.h>
#include <stdlib.h>

#define MAX 4000001

int g[MAX];
int arr[MAX];

int find(int x) {
    if (g[x] != x) {
        g[x] = find(g[x]);
    }
    return g[x];
}

void union_set(int x, int y) {
    x = find(x);
    y = find(y);
    g[x] = y;
}

int upper_bound(int* arr, int size, int num) {
    int l = 0, r = size;
    while (l < r) {
        int m = (l + r) / 2;
        if (arr[m] <= num)
            l = m + 1;
        else
            r = m;
    }
    return l;
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);

    for (int i = 0; i < M; i++) {
        scanf("%d", &arr[i]);
        g[i] = i;
    }
    g[M] = M;

    qsort(arr, M, sizeof(int), compare);

    for (int i = 0; i < K; i++) {
        int num;
        scanf("%d", &num);
        int idx = upper_bound(arr, M, num);
        idx = find(idx);
        printf("%d\n", arr[idx]);
        union_set(idx, idx + 1);
    }

    return 0;
}