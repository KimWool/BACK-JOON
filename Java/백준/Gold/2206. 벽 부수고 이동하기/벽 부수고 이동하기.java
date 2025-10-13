import java.io.*;
import java.util.*;

public class Main {
    static int N, M;
    static int[][] map;
    static boolean[][][] visited;
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};

    static class Node {
        int x, y, dist, broken;
        Node(int x, int y, int dist, int broken) {
            this.x = x;
            this.y = y;
            this.dist = dist;
            this.broken = broken;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        map = new int[N][M];
        for (int i = 0; i < N; i++) {
            String line = br.readLine();
            for (int j = 0; j < M; j++) {
                map[i][j] = line.charAt(j) - '0';
            }
        }

        visited = new boolean[2][N][M];
        System.out.println(bfs());
    }

    static int bfs() {
        Queue<Node> q = new LinkedList<>();
        q.add(new Node(0, 0, 1, 0));
        visited[0][0][0] = true;

        while (!q.isEmpty()) {
            Node cur = q.poll();
            if (cur.x == N - 1 && cur.y == M - 1) return cur.dist;

            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

                if (map[nx][ny] == 0 && !visited[cur.broken][nx][ny]) {
                    visited[cur.broken][nx][ny] = true;
                    q.add(new Node(nx, ny, cur.dist + 1, cur.broken));
                } else if (map[nx][ny] == 1 && cur.broken == 0 && !visited[1][nx][ny]) {
                    visited[1][nx][ny] = true;
                    q.add(new Node(nx, ny, cur.dist + 1, 1));
                }
            }
        }
        return -1;
    }
}