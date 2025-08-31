#include <stdio.h>

#define MAX 1000

typedef struct {
    int row, col, day;
} Point;

int n, m;
int arr[MAX][MAX];
int rowArr[4] = {1, -1, 0, 0};
int colArr[4] = {0, 0, 1, -1};

Point queue[MAX * MAX];
int front = 0, rear = 0;

void enqueue(Point p) {
    queue[rear++] = p;
}

Point dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

int check() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) return 0;
        }
    }
    return 1;
}

void bfs() {
    int day = 0;

    while (!isEmpty()) {
        Point p = dequeue();
        day = p.day;

        for (int i = 0; i < 4; i++) {
            int nr = p.row + rowArr[i];
            int nc = p.col + colArr[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                if (arr[nr][nc] == 0) {
                    arr[nr][nc] = 1;
                    enqueue((Point){nr, nc, day + 1});
                }
            }
        }
    }

    if (check()) {
        printf("%d\n", day);
    } else {
        printf("-1\n");
    }
}

int main() {
    scanf("%d %d", &m, &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 1) {
                enqueue((Point){i, j, 0});
            }
        }
    }

    bfs();
    
    return 0;
}