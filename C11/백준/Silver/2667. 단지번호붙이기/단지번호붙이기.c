#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 25

int N;
int map[MAX][MAX];
int visited[MAX][MAX];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int queueX[MAX * MAX], queueY[MAX * MAX];
int front = 0, rear = 0;

int bfs(int x, int y) {
    int count = 1;
    front = rear = 0;
    queueX[rear] = x;
    queueY[rear++] = y;
    visited[x][y] = 1;

    while (front < rear) {
        int cx = queueX[front];
        int cy = queueY[front++];
        
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
                if (!visited[nx][ny] && map[nx][ny] == 1) {
                    visited[nx][ny] = 1;
                    queueX[rear] = nx;
                    queueY[rear++] = ny;
                    count++;
                }
            }
        }
    }

    return count;
}

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int main() {
    scanf("%d", &N);
    char line[MAX + 1];
    
    for (int i = 0; i < N; i++) {
        scanf("%s", line);
        for (int j = 0; j < N; j++) {
            map[i][j] = line[j] - '0';
        }
    }

    int complex[625]; //25 * 25
    int count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j] && map[i][j] == 1) {
                complex[count++] = bfs(i, j);
            }
        }
    }

    qsort(complex, count, sizeof(int), compare);

    printf("%d\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d\n", complex[i]);
    }

    return 0;
}