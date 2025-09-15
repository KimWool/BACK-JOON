#include <stdio.h>

int arr[1025][1025];
int sum[1025][1025];

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &arr[i][j]);
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + arr[i][j];
        }
    }

    for (int q = 0; q < M; q++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        int result = sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1];
        printf("%d\n", result);
    }

    return 0;
}