#include <stdio.h>

int n, board[10][10];
int white_r[100], white_c[100], white_cnt = 0;
int black_r[100], black_c[100], black_cnt = 0;
int diag1[20], diag2[20];
int max_white = 0, max_black = 0;

void dfs(int idx, int cnt, int r[], int c[], int total, int *max_val) {
    if (idx == total) {
        if (cnt > *max_val) *max_val = cnt;
        return;
    }

    int x = r[idx], y = c[idx];
    if (!diag1[x + y] && !diag2[x - y + n - 1]) {
        diag1[x + y] = 1;
        diag2[x - y + n - 1] = 1;
        dfs(idx + 1, cnt + 1, r, c, total, max_val);
        diag1[x + y] = 0;
        diag2[x - y + n - 1] = 0;
    }
    dfs(idx + 1, cnt, r, c, total, max_val);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &board[i][j]);
            if (board[i][j] == 1) {
                if ((i + j) % 2 == 0) {
                    white_r[white_cnt] = i;
                    white_c[white_cnt++] = j;
                } else {
                    black_r[black_cnt] = i;
                    black_c[black_cnt++] = j;
                }
            }
        }
    }

    dfs(0, 0, white_r, white_c, white_cnt, &max_white);
    dfs(0, 0, black_r, black_c, black_cnt, &max_black);
    printf("%d\n", max_white + max_black);
    return 0;
}