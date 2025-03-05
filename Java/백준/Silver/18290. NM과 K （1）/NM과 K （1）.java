import java.util.Scanner;

public class Main {

    static int N, M, K;
    static int[][] board;
    static boolean[][] visited;
    static int MaxSum = Integer.MIN_VALUE;

    //상하좌우 이동을 위한 델타 배열
    static int[] dx = {0, 0, -1, 1};
    static int[] dy = {-1, 1, 0, 0};

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        //크기가 N * M인 격자판
        N = s.nextInt();
        M = s.nextInt();
        board = new int[N][M];
        visited = new boolean[N][M];

        K = s.nextInt(); //격자판에서 칸 K개를 선택
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                board[i][j] = s.nextInt();
            }
        }

        backtrack(0, 0, 0, 0);
        System.out.println(MaxSum);
    }

    static void backtrack(int count, int sum, int startX, int startY) {
        if (count == K) {
            MaxSum = Math.max(MaxSum, sum);
            return;
        }

        for (int i = startX; i < N; i++) {
            for (int j = (i == startX ? startY : 0); j < M; j++) {
                if (isValid(i, j)) {
                    visited[i][j] = true;
                    backtrack(count + 1, sum + board[i][j], i, j);
                    visited[i][j] = false;
                }
            }
        }
    }

    static boolean isValid(int x, int y) {
        if(visited[x][y]) return false;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < N && ny >= 0 && ny < M && visited[nx][ny]) return false;
        }
        return true;
    }
}