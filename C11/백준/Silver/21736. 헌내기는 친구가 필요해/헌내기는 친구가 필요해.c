#include <stdio.h>

#define MAX 600

typedef struct {
    int x, y;
} Coord;

int N, M;
char map[MAX][MAX + 1];
int visited[MAX][MAX];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

Coord queue[MAX * MAX];
int front = 0, rear = 0;

void enqueue(int x, int y) {
    queue[rear].x = x;
    queue[rear].y = y;
    rear++;
}

Coord dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

int bfs(int x, int y){
    enqueue(x, y);
    visited[x][y] = 1;
    int count = 0;

    while (!isEmpty()) {
        Coord current = dequeue();

        if (map[current.x][current.y] == 'P') {
            count++;
        }

        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
                if (!visited[nx][ny] && map[nx][ny] != 'X') {
                    visited[nx][ny] = 1;
                    enqueue(nx, ny);
                }
            }
        }
    }

    return count;
}

int main(void){
    scanf("%d %d", &N, &M);
    getchar();

    int startX = -1, startY = -1;

    for (int i = 0; i < N; i++) {
        scanf("%s", map[i]);
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 'I') {
                startX = i;
                startY = j;
            }
        }
    }

    int result = bfs(startX, startY);

    if (result == 0) {
        printf("TT");
    } else {
        printf("%d", result);
    }

    return 0;
}