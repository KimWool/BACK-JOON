import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static int[][] space;
    static int[] dx = {-1, 0, 0, 1};
    static int[] dy = {0, -1, 1, 0};
    static int sharkSize = 2;
    static int eatCount = 0;
    static int time = 0;
    static int sharkX, sharkY;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        space = new int[n][n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                space[i][j] = Integer.parseInt(st.nextToken());
                if (space[i][j] == 9) {
                    sharkX = i;
                    sharkY = j;
                    space[i][j] = 0;
                }
            }
        }

        while (true) {
            int[] target = bfs();
            if (target == null) break;
            int x = target[0], y = target[1], dist = target[2];
            time += dist;
            sharkX = x;
            sharkY = y;
            space[x][y] = 0;
            eatCount++;
            if (eatCount == sharkSize) {
                sharkSize++;
                eatCount = 0;
            }
        }

        System.out.println(time);
    }

    static int[] bfs() {
        Queue<int[]> q = new LinkedList<>();
        boolean[][] visited = new boolean[n][n];
        q.add(new int[]{sharkX, sharkY, 0});
        visited[sharkX][sharkY] = true;
        List<int[]> fishes = new ArrayList<>();
        int minDist = Integer.MAX_VALUE;

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0], y = cur[1], dist = cur[2];
            if (dist > minDist) break;
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (visited[nx][ny] || space[nx][ny] > sharkSize) continue;
                visited[nx][ny] = true;
                if (space[nx][ny] != 0 && space[nx][ny] < sharkSize) {
                    fishes.add(new int[]{nx, ny, dist + 1});
                    minDist = dist + 1;
                }
                q.add(new int[]{nx, ny, dist + 1});
            }
        }

        if (fishes.isEmpty()) return null;
        fishes.sort((a, b) -> {
            if (a[2] == b[2]) {
                if (a[0] == b[0]) return a[1] - b[1];
                return a[0] - b[0];
            }
            return a[2] - b[2];
        });
        return fishes.get(0);
    }
}