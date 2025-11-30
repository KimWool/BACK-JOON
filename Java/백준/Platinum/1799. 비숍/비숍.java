import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static int[][] board;
    static boolean[] diag1 = new boolean[40];
    static boolean[] diag2 = new boolean[40];
    static ArrayList<int[]> white = new ArrayList<>();
    static ArrayList<int[]> black = new ArrayList<>();
    static int maxWhite = 0;
    static int maxBlack = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        board = new int[n][n];

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
                if (board[i][j] == 1) {
                    if ((i + j) % 2 == 0) {
                        white.add(new int[]{i, j});
                    } else {
                        black.add(new int[]{i, j});
                    }
                }
            }
        }

        dfs(white, 0, 0, true);
        dfs(black, 0, 0, false);
        System.out.println(maxWhite + maxBlack);
    }

    static void dfs(ArrayList<int[]> list, int idx, int cnt, boolean isWhite) {
        if (idx == list.size()) {
            if (isWhite) {
                maxWhite = Math.max(maxWhite, cnt);
            } else {
                maxBlack = Math.max(maxBlack, cnt);
            }
            return;
        }

        int[] pos = list.get(idx);
        int x = pos[0];
        int y = pos[1];

        if (!diag1[x + y] && !diag2[x - y + n - 1]) {
            diag1[x + y] = true;
            diag2[x - y + n - 1] = true;
            dfs(list, idx + 1, cnt + 1, isWhite);
            diag1[x + y] = false;
            diag2[x - y + n - 1] = false;
        }

        dfs(list, idx + 1, cnt, isWhite);
    }
}