#include <stdio.h>

char arr[3072][6144];

void drawStar(int x, int y, int size) {
    if (size == 3) {
        arr[x][y] = '*';
        arr[x + 1][y - 1] = '*';
        arr[x + 1][y + 1] = '*';
        for (int i = -2; i <= 2; i++) {
            arr[x + 2][y + i] = '*';
        }
        return;
    }

    int newSize = size / 2;
    drawStar(x, y, newSize);
    drawStar(x + newSize, y - newSize, newSize);
    drawStar(x + newSize, y + newSize, newSize);
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2 * N - 1; j++) {
            arr[i][j] = ' ';
        }
    }

    drawStar(0, N - 1, N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2 * N - 1; j++) {
            putchar(arr[i][j]);
        }
        putchar('\n');
    }

    return 0;
}