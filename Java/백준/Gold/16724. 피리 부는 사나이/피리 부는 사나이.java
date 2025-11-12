import java.io.*;
import java.util.*;

public class Main {
    static int n, m;
    static char[][] map;
    static int[][] visited;
    static int count = 0;
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};
    static Map<Character, Integer> dirMap = Map.of('D', 0, 'U', 1, 'R', 2, 'L', 3);

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        map = new char[n][m];
        visited = new int[n][m];
        for (int i = 0; i < n; i++) {
            String line = br.readLine();
            for (int j = 0; j < m; j++) {
                map[i][j] = line.charAt(j);
            }
        }

        int id = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] == 0) {
                    dfs(i, j, id++);
                }
            }
        }

        System.out.println(count);
    }

    static void dfs(int x, int y, int id) {
        visited[x][y] = id;
        int dir = dirMap.get(map[x][y]);
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (visited[nx][ny] == 0) {
            dfs(nx, ny, id);
        } else if (visited[nx][ny] == id) {
            count++;
        }
    }
}