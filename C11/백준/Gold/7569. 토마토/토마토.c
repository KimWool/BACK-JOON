#include <stdio.h>
#include <stdlib.h>

#define MAX_H 100
#define MAX_N 100
#define MAX_M 100

typedef struct {
    int height, row, col;
} PointXYZ;

int rowArr[] = {-1, 0, 1, 0, 0, 0};
int colArr[] = {0, 1, 0, -1, 0, 0};
int heightArr[] = {0, 0, 0, 0, 1, -1};

int m, n, h;
int arr[MAX_H + 1][MAX_N + 1][MAX_M + 1];
PointXYZ queue[MAX_H * MAX_N * MAX_M];
int front = 0, rear = 0;

void enqueue(PointXYZ p) {
    queue[rear++] = p;
}

PointXYZ dequeue() {
    return queue[front++];
}

int checkPoint(int height, int row, int col) {
    if (height < 1 || height > h || row < 1 || row > n || col < 1 || col > m) return 0;
    if (arr[height][row][col] == 0) return 1;
    return 0;
}

int bfs() {
    while (front < rear) {
        PointXYZ point = dequeue();
        int height = point.height;
        int row = point.row;
        int col = point.col;

        for (int i = 0; i < 6; i++) {
            int moveHeight = height + heightArr[i];
            int moveRow = row + rowArr[i];
            int moveCol = col + colArr[i];
            if (checkPoint(moveHeight, moveRow, moveCol)) {
                enqueue((PointXYZ){moveHeight, moveRow, moveCol});
                arr[moveHeight][moveRow][moveCol] = arr[height][row][col] + 1;
            }
        }
    }

    int result = -1;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                if (arr[i][j][k] == 0) return -1;
                if (arr[i][j][k] > result) result = arr[i][j][k];
            }
        }
    }

    if (result == 1) return 0;
    return result - 1;
}

int main() {
    scanf("%d %d %d", &m, &n, &h);

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                scanf("%d", &arr[i][j][k]);
                if (arr[i][j][k] == 1) {
                    enqueue((PointXYZ){i, j, k});
                }
            }
        }
    }

    printf("%d\n", bfs());
    return 0;
}