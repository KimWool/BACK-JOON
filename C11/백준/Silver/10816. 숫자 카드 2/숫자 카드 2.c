#include <stdio.h>

#define OFFSET 10000000
#define MAX 20000001

int count[MAX] = {0};

int main() {
    int N, M;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        count[x + OFFSET]++;
    }

    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int x;
        scanf("%d", &x);
        printf("%d ", count[x + OFFSET]);
    }

    return 0;
}