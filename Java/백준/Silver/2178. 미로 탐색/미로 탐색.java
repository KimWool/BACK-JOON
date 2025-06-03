import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {

    static int N, M;
    static int[][] map;
    static boolean[][] visited;

    //상, 하, 좌, 우
    static int[] dx = {0, 0, -1, 1};
    static int[] dy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] campus = br.readLine().split(" ");
        N = Integer.parseInt(campus[0]);
        M = Integer.parseInt(campus[1]);

        map = new int[N][M];
        visited = new boolean[N][M];

        int startX = 0, startY = 0;

        for (int i = 0; i < N; i++) {
            String line = br.readLine();
            for (int j = 0; j < M; j++) {
                map[i][j] = line.charAt(j) - '0';
            }
        }

        int result = bfs(startX, startY);
        System.out.print(result);
    }

    static int bfs(int x, int y) {
        Queue<int[]> q = new LinkedList<>();
        int[][] dist = new int[N][M];
        visited[x][y] = true;
        dist[x][y] = 1;

        q.offer(new int[]{x, y});

        while (!q.isEmpty()) {
            int[] now = q.poll();
            int cX = now[0], cY = now[1];

            if (cX == N - 1 && cY == M - 1) {
                return dist[cX][cY];
            }

            for (int i = 0; i < 4; i++) {
                int nx = cX + dx[i], ny = cY + dy[i];
                if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
                    if (!visited[nx][ny] && map[nx][ny] == 1) {
                        visited[nx][ny] = true;
                        dist[nx][ny] = dist[cX][cY] + 1;
                        q.offer(new int[]{nx, ny});
                    }
                }
            }
        }

        return 0;
    }
}