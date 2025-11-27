#include <stdio.h>
#include <string.h>

int n, result = 0;

void copy_board(int src[20][20], int dest[20][20]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dest[i][j] = src[i][j];
}

void move(int board[20][20], int dir) {
    for (int i = 0; i < n; i++) {
        int temp[20] = {0}, idx = 0;
        int last = 0;

        for (int j = 0; j < n; j++) {
            int x = i, y = j;
            if (dir == 0) x = j, y = i;
            else if (dir == 1) x = n - 1 - j, y = i;
            else if (dir == 2) x = i, y = j;
            else x = i, y = n - 1 - j;

            int val = board[x][y];
            if (val == 0) continue;

            if (last == val) {
                temp[idx - 1] *= 2;
                last = 0;
            } else {
                temp[idx++] = val;
                last = val;
            }
        }

        for (int j = 0; j < n; j++) {
            int x = i, y = j;
            if (dir == 0) x = j, y = i;
            else if (dir == 1) x = n - 1 - j, y = i;
            else if (dir == 2) x = i, y = j;
            else x = i, y = n - 1 - j;

            board[x][y] = temp[j];
        }
    }
}

void dfs(int board[20][20], int depth) {
    if (depth == 5) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (result < board[i][j]) result = board[i][j];
        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        int new_board[20][20];
        copy_board(board, new_board);
        move(new_board, dir);
        dfs(new_board, depth + 1);
    }
}

int main() {
    int board[20][20];
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &board[i][j]);

    dfs(board, 0);
    printf("%d\n", result);
    return 0;
}