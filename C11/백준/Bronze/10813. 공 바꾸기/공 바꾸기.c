#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int basket[101];
    for (int i = 0; i < N; i++) {
        basket[i] = i + 1;
    }

    for (int m = 0; m < M; m++) {
        int i, j;
        scanf("%d %d", &i, &j);
        int temp = basket[i - 1];
        basket[i - 1] = basket[j - 1];
        basket[j - 1] = temp;
    }

    for (int i = 0; i < N; i++) {
        printf("%d ", basket[i]);
    }

    return 0;
}