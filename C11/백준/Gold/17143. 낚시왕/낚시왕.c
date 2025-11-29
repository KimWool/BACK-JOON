#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int r, c, s, d, z;
    int alive;
} Shark;

int R, C, M;
Shark sharks[10001];
int map[101][101];

int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};

void catch_shark(int king, int* total) {
    for (int i = 1; i <= R; i++) {
        int idx = map[i][king];
        if (idx != 0 && sharks[idx].alive) {
            *total += sharks[idx].z;
            sharks[idx].alive = 0;
            map[i][king] = 0;
            break;
        }
    }
}

void move_sharks() {
    int temp[101][101] = {0};

    for (int i = 1; i <= M; i++) {
        if (!sharks[i].alive) continue;

        int r = sharks[i].r;
        int c = sharks[i].c;
        int s = sharks[i].s;
        int d = sharks[i].d;

        if (d == 1 || d == 2) s %= (2 * (R - 1));
        else s %= (2 * (C - 1));

        for (int j = 0; j < s; j++) {
            int nr = r + dx[d];
            int nc = c + dy[d];

            if (nr < 1 || nr > R || nc < 1 || nc > C) {
                if (d == 1) d = 2;
                else if (d == 2) d = 1;
                else if (d == 3) d = 4;
                else if (d == 4) d = 3;
                nr = r + dx[d];
                nc = c + dy[d];
            }
            r = nr;
            c = nc;
        }

        sharks[i].r = r;
        sharks[i].c = c;
        sharks[i].d = d;

        if (temp[r][c] == 0) {
            temp[r][c] = i;
        } else {
            int other = temp[r][c];
            if (sharks[other].z < sharks[i].z) {
                sharks[other].alive = 0;
                temp[r][c] = i;
            } else {
                sharks[i].alive = 0;
            }
        }
    }

    memset(map, 0, sizeof(map));
    for (int i = 1; i <= M; i++) {
        if (sharks[i].alive) {
            map[sharks[i].r][sharks[i].c] = i;
        }
    }
}

int main() {
    scanf("%d %d %d", &R, &C, &M);

    for (int i = 1; i <= M; i++) {
        scanf("%d %d %d %d %d", &sharks[i].r, &sharks[i].c, &sharks[i].s, &sharks[i].d, &sharks[i].z);
        sharks[i].alive = 1;
        map[sharks[i].r][sharks[i].c] = i;
    }

    int total = 0;

    for (int king = 1; king <= C; king++) {
        catch_shark(king, &total);
        move_sharks();
    }

    printf("%d\n", total);
    return 0;
}