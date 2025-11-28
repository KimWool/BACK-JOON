#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
#define INF 987654321

typedef struct {
    int rx, ry, bx, by, depth;
} State;

int n, m;
char board[MAX][MAX];
int visited[MAX][MAX][MAX][MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int move(int *x, int *y, int dx, int dy) {
    int count = 0;
    while (board[*x + dx][*y + dy] != '#' && board[*x][*y] != 'O') {
        *x += dx;
        *y += dy;
        count++;
    }
    return count;
}

int bfs(int rx, int ry, int bx, int by) {
    State queue[10000];
    int front = 0, rear = 0;

    queue[rear++] = (State){rx, ry, bx, by, 0};
    visited[rx][ry][bx][by] = 1;

    while (front < rear) {
        State cur = queue[front++];
        if (cur.depth >= 10) return -1;

        for (int dir = 0; dir < 4; dir++) {
            int nrx = cur.rx, nry = cur.ry;
            int nbx = cur.bx, nby = cur.by;

            int r_count = move(&nrx, &nry, dx[dir], dy[dir]);
            int b_count = move(&nbx, &nby, dx[dir], dy[dir]);

            if (board[nbx][nby] == 'O') continue;
            if (board[nrx][nry] == 'O') return cur.depth + 1;

            if (nrx == nbx && nry == nby) {
                if (r_count > b_count) {
                    nrx -= dx[dir];
                    nry -= dy[dir];
                } else {
                    nbx -= dx[dir];
                    nby -= dy[dir];
                }
            }

            if (!visited[nrx][nry][nbx][nby]) {
                visited[nrx][nry][nbx][nby] = 1;
                queue[rear++] = (State){nrx, nry, nbx, nby, cur.depth + 1};
            }
        }
    }

    return -1;
}

int main() {
    scanf("%d %d", &n, &m);
    int rx, ry, bx, by;

    for (int i = 0; i < n; i++) {
        scanf("%s", board[i]);
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'R') {
                rx = i;
                ry = j;
            } else if (board[i][j] == 'B') {
                bx = i;
                by = j;
            }
        }
    }

    printf("%d\n", bfs(rx, ry, bx, by));
    return 0;
}