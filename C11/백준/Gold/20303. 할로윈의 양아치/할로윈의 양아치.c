#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 30001
#define MAX_K 3001

int parent[MAX_N];
int candy[MAX_N];
int group_size[MAX_N];
int group_candy[MAX_N];
int dp[MAX_K];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void union_set(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if (pa != pb) parent[pb] = pa;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);

    for (int i = 1; i <= N; i++) {
        scanf("%d", &candy[i]);
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        union_set(a, b);
    }

    memset(group_size, 0, sizeof(group_size));
    memset(group_candy, 0, sizeof(group_candy));

    for (int i = 1; i <= N; i++) {
        int root = find(i);
        group_size[root]++;
        group_candy[root] += candy[i];
    }

    for (int i = 1; i <= N; i++) {
        if (parent[i] != i) continue;

        int weight = group_size[i];
        int value = group_candy[i];

        for (int j = K - 1; j >= weight; j--) {
            dp[j] = max(dp[j], dp[j - weight] + value);
        }
    }

    printf("%d\n", dp[K - 1]);
    return 0;
}