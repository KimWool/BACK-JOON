import java.util.Scanner;

public class Main {

    static int N, M = 0;
    static int maxSum = 0;

    static int[][] board;
    static boolean[][] visited;

    static int[] dx = {0, 0, 1, -1};
    static int[] dy = {1, -1, 0, 0};

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        N = s.nextInt(); //종이의 세로 크기
        M = s.nextInt(); //종이의 가로 크기

        //종이에 채워져 있는 수 입력받기
        board = new int[N][M];
        visited = new boolean[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                board[i][j] = s.nextInt();
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                visited[i][j] = true;
                DFS(i, j, 1, board[i][j]);
                visited[i][j] = false;
                checkTshapes(i, j);
            }
        }
        System.out.println(maxSum);
    }

    static void DFS(int x, int y, int depth, int sum) {
        if (depth == 4) {
            maxSum = Math.max(maxSum, sum);
            return;
        }

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX >= 0 && newY >= 0 && newX < N && newY < M && !visited[newX][newY]) {
                visited[newX][newY] = true;
                DFS(newX, newY, depth + 1, sum + board[newX][newY]);
                visited[newX][newY] = false;
            }
        }
    }

    static void checkTshapes(int x, int y) {
        int[][][] shapes = {
                {{0, 1}, {0, -1}, {1, 0}}, //ㅜ
                {{0, 1}, {0, -1}, {-1, 0}}, //ㅗ
                {{1, 0}, {-1, 0}, {0, 1}}, //ㅏ
                {{1, 0}, {-1, 0}, {0, -1}} //ㅓ
        };

        for (int[][] shape : shapes) {
            int sum = board[x][y];
            boolean valid = true;

            for (int[] move : shape) {
                int newX = x + move[0];
                int newY = y + move[1];

                if (newX < 0 || newY < 0 || newX >= N || newY >= M) {
                    valid = false;
                    break;
                }
                sum += board[newX][newY];
            }
            if (valid) {
                maxSum = Math.max(maxSum, sum);
            }
        }
    }
}