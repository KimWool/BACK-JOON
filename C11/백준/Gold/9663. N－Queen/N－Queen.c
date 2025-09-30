#include <stdio.h>
#include <stdlib.h>

int N;
int count = 0;
int *board;

int isPossible(int col) {
    for (int i = 0; i < col; i++) {
        if (board[col] == board[i]) return 0;
        if (abs(col - i) == abs(board[col] - board[i])) return 0;
    }
    return 1;
}

void dfs(int depth) {
    if (depth == N) {
        count++;
        return;
    }
    for (int i = 0; i < N; i++) {
        board[depth] = i;
        if (isPossible(depth)) {
            dfs(depth + 1);
        }
    }
}

int main(void) {
    scanf("%d", &N);
    board = (int*)malloc(sizeof(int) * N);
    dfs(0);
    printf("%d\n", count);
    free(board);
    return 0;
}