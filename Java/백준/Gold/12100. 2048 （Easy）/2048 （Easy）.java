import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static int[][] board;
    static int result = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        board = new int[n][n];

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        dfs(board, 0);
        System.out.println(result);
    }

    static void dfs(int[][] map, int depth) {
        if (depth == 5) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    result = Math.max(result, map[i][j]);
                }
            }
            return;
        }

        for (int d = 0; d < 4; d++) {
            int[][] copied = copy(map);
            move(copied, d);
            dfs(copied, depth + 1);
        }
    }

    static int[][] copy(int[][] map) {
        int[][] newMap = new int[n][n];
        for (int i = 0; i < n; i++) {
            System.arraycopy(map[i], 0, newMap[i], 0, n);
        }
        return newMap;
    }

    static void move(int[][] map, int dir) {
        for (int i = 0; i < n; i++) {
            Deque<Integer> queue = new LinkedList<>();

            for (int j = 0; j < n; j++) {
                int value;
                if (dir == 0) value = map[j][i];
                else if (dir == 1) value = map[n - 1 - j][i];
                else if (dir == 2) value = map[i][j];
                else value = map[i][n - 1 - j];

                if (value != 0) queue.add(value);
            }

            Deque<Integer> merged = new LinkedList<>();
            while (!queue.isEmpty()) {
                int current = queue.poll();
                if (!queue.isEmpty() && current == queue.peek()) {
                    merged.add(current * 2);
                    queue.poll();
                } else {
                    merged.add(current);
                }
            }

            for (int j = 0; j < n; j++) {
                int val = merged.isEmpty() ? 0 : merged.poll();
                if (dir == 0) map[j][i] = val;
                else if (dir == 1) map[n - 1 - j][i] = val;
                else if (dir == 2) map[i][j] = val;
                else map[i][n - 1 - j] = val;
            }
        }
    }
}