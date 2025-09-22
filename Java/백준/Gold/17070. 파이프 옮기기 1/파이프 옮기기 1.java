import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int[][] map;
    static int count = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        map = new int[N][N];
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        dfs(0, 1, 0);
        System.out.println(count);
    }

    static void dfs(int r, int c, int dir) {
        if (r == N - 1 && c == N - 1) {
            count++;
            return;
        }

        if (dir == 0 || dir == 2) {
            if (c + 1 < N && map[r][c + 1] == 0) {
                dfs(r, c + 1, 0);
            }
        }

        if (dir == 1 || dir == 2) {
            if (r + 1 < N && map[r + 1][c] == 0) {
                dfs(r + 1, c, 1);
            }
        }

        if (r + 1 < N && c + 1 < N) {
            if (map[r][c + 1] == 0 && map[r + 1][c] == 0 && map[r + 1][c + 1] == 0) {
                dfs(r + 1, c + 1, 2);
            }
        }
    }
}