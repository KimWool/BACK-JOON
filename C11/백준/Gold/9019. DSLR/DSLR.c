#include <stdio.h>
#include <stdbool.h>

#define MAX 10000

typedef struct {
    int val;
} Node;

int D(int n) { return (2 * n) % 10000; }
int S(int n) { return n == 0 ? 9999 : n - 1; }
int L(int n) { return (n % 1000) * 10 + n / 1000; }
int R(int n) { return (n % 10) * 1000 + n / 10; }

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int A, B;
        scanf("%d %d", &A, &B);

        bool visited[MAX] = {false};
        int parent[MAX];
        char how[MAX];
        Node queue[MAX];

        int front = 0, rear = 0;
        queue[rear++].val = A;
        visited[A] = true;
        parent[A] = -1;

        while (front < rear) {
            int cur = queue[front++].val;
            if (cur == B) break;

            int next;

            next = D(cur);
            if (!visited[next]) {
                visited[next] = true;
                parent[next] = cur;
                how[next] = 'D';
                queue[rear++].val = next;
            }

            next = S(cur);
            if (!visited[next]) {
                visited[next] = true;
                parent[next] = cur;
                how[next] = 'S';
                queue[rear++].val = next;
            }

            next = L(cur);
            if (!visited[next]) {
                visited[next] = true;
                parent[next] = cur;
                how[next] = 'L';
                queue[rear++].val = next;
            }

            next = R(cur);
            if (!visited[next]) {
                visited[next] = true;
                parent[next] = cur;
                how[next] = 'R';
                queue[rear++].val = next;
            }
        }

        char result[10000];
        int len = 0;
        for (int cur = B; parent[cur] != -1; cur = parent[cur]) {
            result[len++] = how[cur];
        }
        for (int i = len - 1; i >= 0; i--) putchar(result[i]);
        putchar('\n');
    }

    return 0;
}