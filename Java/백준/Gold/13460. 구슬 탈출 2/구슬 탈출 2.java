import java.io.*;
import java.util.*;

public class Main {
    static int n, m;
    static char[][] board;
    static boolean[][][][] visited;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        board = new char[n][m];
        visited = new boolean[n][m][n][m];
        int rx = 0, ry = 0, bx = 0, by = 0;

        for (int i = 0; i < n; i++) {
            String line = br.readLine();
            for (int j = 0; j < m; j++) {
                board[i][j] = line.charAt(j);
                if (board[i][j] == 'R') {
                    rx = i;
                    ry = j;
                } else if (board[i][j] == 'B') {
                    bx = i;
                    by = j;
                }
            }
        }

        System.out.println(bfs(rx, ry, bx, by));
    }

    static int bfs(int rx, int ry, int bx, int by) {
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{rx, ry, bx, by, 0});
        visited[rx][ry][bx][by] = true;

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            if (cur[4] >= 10) return -1;

            for (int d = 0; d < 4; d++) {
                int[] nRed = move(cur[0], cur[1], dx[d], dy[d]);
                int[] nBlue = move(cur[2], cur[3], dx[d], dy[d]);

                if (board[nBlue[0]][nBlue[1]] == 'O') continue;
                if (board[nRed[0]][nRed[1]] == 'O') return cur[4] + 1;

                if (nRed[0] == nBlue[0] && nRed[1] == nBlue[1]) {
                    if (nRed[2] > nBlue[2]) {
                        nRed[0] -= dx[d];
                        nRed[1] -= dy[d];
                    } else {
                        nBlue[0] -= dx[d];
                        nBlue[1] -= dy[d];
                    }
                }

                if (!visited[nRed[0]][nRed[1]][nBlue[0]][nBlue[1]]) {
                    visited[nRed[0]][nRed[1]][nBlue[0]][nBlue[1]] = true;
                    q.offer(new int[]{nRed[0], nRed[1], nBlue[0], nBlue[1], cur[4] + 1});
                }
            }
        }

        return -1;
    }

    static int[] move(int x, int y, int dx, int dy) {
        int count = 0;
        while (true) {
            if (board[x + dx][y + dy] == '#' || board[x][y] == 'O') break;
            x += dx;
            y += dy;
            count++;
        }
        return new int[]{x, y, count};
    }
}