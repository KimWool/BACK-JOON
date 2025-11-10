#include <stdio.h>
#include <string.h>

#define MAX 100001

int student[MAX];
int visited[MAX];
int finished[MAX];
int count;

void dfs(int x) {
    visited[x] = 1;
    int next = student[x];

    if (!visited[next]) {
        dfs(next);
    } else if (!finished[next]) {
        count++;
        for (int i = next; i != x; i = student[i]) {
            count++;
        }
    }

    finished[x] = 1;
}

int main() {
    int t, n;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        for (int i = 1; i <= n; i++) {
            scanf("%d", &student[i]);
        }

        memset(visited, 0, sizeof(int) * (n + 1));
        memset(finished, 0, sizeof(int) * (n + 1));
        count = 0;

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }

        printf("%d\n", n - count);
    }

    return 0;
}