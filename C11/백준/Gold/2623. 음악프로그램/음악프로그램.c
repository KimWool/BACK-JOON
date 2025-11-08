#include <stdio.h>
#include <stdlib.h>

#define MAX 1001

int adj[MAX][MAX];
int indegree[MAX];
int result[MAX];
int queue[MAX];
int front = 0, rear = 0;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int k, prev, curr;
        scanf("%d", &k);
        if (k > 0) scanf("%d", &prev);
        for (int j = 1; j < k; j++) {
            scanf("%d", &curr);
            if (adj[prev][curr] == 0) {
                adj[prev][curr] = 1;
                indegree[curr]++;
            }
            prev = curr;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int idx = 0;
    while (front < rear) {
        int now = queue[front++];
        result[idx++] = now;
        for (int i = 1; i <= n; i++) {
            if (adj[now][i]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    if (idx != n) {
        printf("0\n");
    } else {
        for (int i = 0; i < idx; i++) {
            printf("%d\n", result[i]);
        }
    }

    return 0;
}