import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static int[][] map;
    static boolean[][] visited;
    static int M, N;

    static int[] dx = {0, 0, 1, -1};
    static int[] dy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine()); //테스트 케이스의 개수
        for (int i = 0; i < T; i++) {
            String[] input = br.readLine().split(" ");
            M = Integer.parseInt(input[0]); //배추 밭의 가로 길이
            N = Integer.parseInt(input[1]); //배추 밭의 세로 길이
            int K = Integer.parseInt(input[2]); //배추가 심어져 있는 위치의 개수

            map = new int[N][M]; //배추 위치
            visited = new boolean[N][M];

            for (int j = 0; j < K; j++) { //배추의 위치
                String[] coordinates = br.readLine().split(" ");
                int x = Integer.parseInt(coordinates[0]);
                int y = Integer.parseInt(coordinates[1]);
                map[y][x] = 1;
            }

            int worms = 0; //배추흰지렁이 마리 수

            for (int j = 0; j < N; j++) {
                for (int k = 0; k < M; k++) {
                    if (map[j][k] == 1 && !visited[j][k]) {
                        dfs(j, k);
                        worms++;
                    }
                }
            }

            System.out.println(worms);
        }
    }

    static void dfs(int y, int x) {
        visited[y][x] = true;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
                if (!visited[ny][nx] && map[ny][nx] == 1) {
                    dfs(ny, nx);
                }
            }
        }
    }
}