import java.util.Scanner;

public class Main {

    public static int countRepaint(char[][] board, int x, int y, char startColor){
        int count = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                char expected = ((i + j) % 2 == 0) ? startColor : (startColor == 'W' ? 'B' : 'W');
                if (board[x + i][y + j] != expected) { count++; }
            }
        }
        return count;
    }

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int M = s.nextInt();
        int N = s.nextInt();
        s.nextLine();

        char[][] board = new char[M][N]; //M*N 크기의 보드
        for (int i = 0; i < M; i++) {
            String line = s.nextLine();
            for (int j = 0; j < N; j++) {
              board[i][j] = line.charAt(j);
            }
        }

        int min = Integer.MAX_VALUE;

        for (int x = 0; x <= M - 8; x++) {
            for (int y = 0; y <= N - 8; y++) {
                int repaintW = countRepaint(board, x, y, 'W');
                int repaintB = countRepaint(board, x, y, 'B');
                min = Math.min(min, Math.min(repaintW, repaintB));
            }
        }

        System.out.print(min);

        s.close();
    }
}