import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    static int[][] sudoku = new int[9][9];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        for (int i = 0; i < 9; i++) {
            String line = br.readLine();
            for (int j = 0; j < 9; j++) {
                sudoku[i][j] = line.charAt(j) - '0';
            }
        }

        solve(0, 0);
    }

    static void solve(int row, int col) {
        if (col == 9) {
            solve(row + 1, 0);
            return;
        }

        if (row == 9) {
            printSudoku();
            System.exit(0);
        }

        if (sudoku[row][col] == 0) {
            for (int num = 1; num <= 9; num++) {
                if (isValid(row, col, num)) {
                    sudoku[row][col] = num;
                    solve(row, col + 1);
                    sudoku[row][col] = 0;
                }
            }
        } else {
            solve(row, col + 1);
        }
    }

    static boolean isValid(int row, int col, int num) {
        for (int i = 0; i < 9; i++) {
            if (sudoku[row][i] == num || sudoku[i][col] == num) {
                return false;
            }
        }

        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (sudoku[i][j] == num) {
                    return false;
                }
            }
        }

        return true;
    }

    static void printSudoku() {
        StringBuilder sb = new StringBuilder();
        for (int[] row : sudoku) {
            for (int val : row) {
                sb.append(val);
            }
            sb.append("\n");
        }
        System.out.print(sb);
    }
}