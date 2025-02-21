import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int N = s.nextInt(); //보드의 크기 (N * N)
        s.nextLine();

        //보드에 채워져 있는 사탕의 색상 입력받기
        char[][] candy = new char[N][N];
        for (int i = 0; i < N; i++) {
            String line = s.nextLine();
            candy[i] = line.toCharArray();
        }

        //초기 사탕의 최대 개수 계산
        int max = Count(candy, N);

        //최대 개수가 N이 아닌 경우 사탕 교환
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (j + 1 < N && candy[i][j] != candy[i][j + 1]) {
                    //오른쪽 칸과 교환
                    swap(candy, i, j, i, j + 1);
                    max = Math.max(max, Count(candy, N));
                    swap(candy, i, j, i, j + 1);
                }
                if (i + 1 < N && candy[i][j] != candy[i + 1][j]) {
                    //아래쪽 칸과 교환
                    swap(candy, i, j, i + 1, j);
                    max = Math.max(max, Count(candy, N));
                    swap(candy, i, j, i + 1, j);
                }
            }
        }

        System.out.print(max);
    }

    public static void swap(char[][] board, int i1, int j1, int i2, int j2) {
        char temp = board[i1][j1];
        board[i1][j1] = board[i2][j2];
        board[i2][j2] = temp;
    }

    public static int Count(char[][] board, int N) {
        int max = 0;

        //연속된 사탕(행)의 색 개수 계산
        for (int i = 0; i < N; i++) {
            int count = 1;
            for (int j = 1; j < N; j++) {
                if (board[i][j] == board[i][j - 1]) {
                    count++;
                } else {
                    max = Math.max(max, count);
                    count = 1;
                }
            }
            max = Math.max(max, count);
        }

        //연속된 사탕(열)의 색 개수 계산
        for (int j = 0; j < N; j++) {
            int count = 1;
            for (int i = 1; i < N; i++) {
                if (board[i][j] == board[i - 1][j]) {
                    count++;
                } else {
                    max = Math.max(max, count);
                    count = 1;
                }
            }
            max = Math.max(max, count);
        }

        return max;
    }
}