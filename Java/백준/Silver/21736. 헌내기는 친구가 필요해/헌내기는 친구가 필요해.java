import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {

    static int N, M;
    static char[][] map;
    static boolean[][] visited;

    //상, 하, 좌, 우
    static int[] dx = {0, 0, -1, 1};
    static int[] dy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] campus = br.readLine().split(" ");
        N = Integer.parseInt(campus[0]);
        M = Integer.parseInt(campus[1]);

        map = new char[N][M];
        visited = new boolean[N][M];

        int startX = 0, startY = 0;

        for (int i = 0; i < N; i++) {
            String line = br.readLine();
            for (int j = 0; j < M; j++) {
                map[i][j] = line.charAt(j);
                if (map[i][j] == 'I') {
                    startX = i;
                    startY = j;
                }
            }
        }

        int result = bfs(startX, startY);
        System.out.print(result == 0 ? "TT" : result);
    }

    static int bfs(int x, int y) {
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{x, y});
        visited[x][y] = true;
        int count = 0;

        while (!q.isEmpty()) {
            int[] now = q.poll();
            int cX = now[0], cY = now[1];

            if (map[cX][cY] == 'P') { //사람을 만난 경우
                count++;
            }

            for (int i = 0; i < 4; i++) {
                int nx = cX + dx[i], ny = cY + dy[i];
                if (nx >= 0 && ny >= 0 && nx < N && ny < M) { //캠퍼스 밖으로 나갈 수 없음
                    if (!visited[nx][ny] && map[nx][ny] != 'X') { //벽으로는 이동할 수 없음
                        visited[nx][ny] = true;
                        q.offer(new int[]{nx, ny});
                    }
                }
            }
        }

        return count;
    }
}