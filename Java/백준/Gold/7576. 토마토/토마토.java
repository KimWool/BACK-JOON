import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int n, m;
    static int[][] arr;
    static int[] rowArr = {1, -1, 0, 0};
    static int[] colArr = {0, 0, 1, -1};
    static Queue<Point> queue = new LinkedList<>();

    static class Point {
        int row, col, day;
        public Point(int row, int col, int day) {
            this.row = row;
            this.col = col;
            this.day = day;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());

        arr = new int[n][m];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                if (arr[i][j] == 1) {
                    queue.add(new Point(i, j, 0));
                }
            }
        }

        bfs();
    }

    static void bfs() {
        int day = 0;

        while (!queue.isEmpty()) {
            Point p = queue.poll();
            day = p.day;

            for (int i = 0; i < 4; i++) {
                int nr = p.row + rowArr[i];
                int nc = p.col + colArr[i];

                if (0 <= nr && nr < n && 0 <= nc && nc < m) {
                    if (arr[nr][nc] == 0) {
                        arr[nr][nc] = 1;
                        queue.add(new Point(nr, nc, day + 1));
                    }
                }
            }
        }

        if (check()) {
            System.out.println(day);
        } else {
            System.out.println(-1);
        }
    }

    static boolean check() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 0)
                    return false;
            }
        }
        return true;
    }
}