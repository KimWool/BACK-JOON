import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    static int N;
    static int[] board;
    static int count = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        board = new int[N];
        dfs(0);
        System.out.println(count);
    }

    static void dfs(int depth) {
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

    static boolean isPossible(int col) {
        for (int i = 0; i < col; i++) {
            if (board[col] == board[i]) return false;
            if (Math.abs(col - i) == Math.abs(board[col] - board[i])) return false;
        }
        return true;
    }
}