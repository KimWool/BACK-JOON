#include <stdio.h>
#include <stdlib.h>

int N, M;
int arr[8], uniqueArr[8], U;
int seq[8];

int cmp(const void *a, const void *b) {
    int x = *(int *)a, y = *(int *)b;
    return x - y;
}

void dfs(int depth, int start) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            if (i) printf(" ");
            printf("%d", seq[i]);
        }
        printf("\n");
        return;
    }
    for (int i = start; i < U; i++) {
        seq[depth] = uniqueArr[i];
        dfs(depth + 1, i);
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    qsort(arr, N, sizeof(int), cmp);

    U = 0;
    int prev = -1;
    for (int i = 0; i < N; i++) {
        if (i == 0 || arr[i] != prev) {
            uniqueArr[U++] = arr[i];
            prev = arr[i];
        }
    }

    dfs(0, 0);
    return 0;
}