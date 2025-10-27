#include <stdio.h>
#include <stdlib.h>

int sudoku[9][9];

int is_valid(int row, int col, int num) {
    for (int i = 0; i < 9; i++) {
        if (sudoku[row][i] == num || sudoku[i][col] == num)
            return 0;
    }

    int start_row = (row / 3) * 3;
    int start_col = (col / 3) * 3;

    for (int i = start_row; i < start_row + 3; i++) {
        for (int j = start_col; j < start_col + 3; j++) {
            if (sudoku[i][j] == num)
                return 0;
        }
    }

    return 1;
}

void print_sudoku() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d", sudoku[i][j]);
        }
        printf("\n");
    }
    exit(0);
}

void solve(int row, int col) {
    if (col == 9) {
        solve(row + 1, 0);
        return;
    }

    if (row == 9) {
        print_sudoku();
    }

    if (sudoku[row][col] == 0) {
        for (int num = 1; num <= 9; num++) {
            if (is_valid(row, col, num)) {
                sudoku[row][col] = num;
                solve(row, col + 1);
                sudoku[row][col] = 0;
            }
        }
    } else {
        solve(row, col + 1);
    }
}

int main() {
    for (int i = 0; i < 9; i++) {
        char line[10];
        scanf("%s", line);
        for (int j = 0; j < 9; j++) {
            sudoku[i][j] = line[j] - '0';
        }
    }

    solve(0, 0);
    return 0;
}