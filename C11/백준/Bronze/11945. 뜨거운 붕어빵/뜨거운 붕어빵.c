#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int fish[N][M];

    for (int i = 0; i < N; i++) {
        char line[M + 1];
        scanf("%s", line);
        for (int j = 0; j < M; j++) {
            fish[i][j] = line[j] - '0';
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = M - 1; j >= 0; j--) {
            printf("%d", fish[i][j]);
        }
        printf("\n");
    }

    return 0;
}