import java.io.*;
import java.util.*;

public class Main {
    static int h, w;
    static char[][] map;
    static boolean[][] visited;
    static boolean[] key;
    static List<int[]>[] door;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            h = Integer.parseInt(st.nextToken());
            w = Integer.parseInt(st.nextToken());
            map = new char[h + 2][w + 2];
            visited = new boolean[h + 2][w + 2];
            key = new boolean[26];
            door = new ArrayList[26];

            for (int i = 0; i < 26; i++) door[i] = new ArrayList<>();

            for (int i = 1; i <= h; i++) {
                String line = br.readLine();
                for (int j = 1; j <= w; j++) {
                    map[i][j] = line.charAt(j - 1);
                }
            }

            Arrays.fill(map[0], '.');
            Arrays.fill(map[h + 1], '.');
            for (int i = 1; i <= h; i++) {
                map[i][0] = '.';
                map[i][w + 1] = '.';
            }

            String keys = br.readLine();
            if (!keys.equals("0")) {
                for (char c : keys.toCharArray()) {
                    key[c - 'a'] = true;
                }
            }

            System.out.println(bfs());
        }
    }

    static int bfs() {
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{0, 0});
        visited[0][0] = true;
        int count = 0;

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur[0] + dx[dir];
                int ny = cur[1] + dy[dir];

                if (nx < 0 || ny < 0 || nx >= h + 2 || ny >= w + 2 || visited[nx][ny]) continue;

                char c = map[nx][ny];
                if (c == '*') continue;
                visited[nx][ny] = true;

                if (c == '$') {
                    count++;
                    q.add(new int[]{nx, ny});
                } else if (c >= 'A' && c <= 'Z') {
                    if (key[c - 'A']) {
                        q.add(new int[]{nx, ny});
                    } else {
                        door[c - 'A'].add(new int[]{nx, ny});
                    }
                } else if (c >= 'a' && c <= 'z') {
                    if (!key[c - 'a']) {
                        key[c - 'a'] = true;
                        q.add(new int[]{nx, ny});
                        for (int[] pos : door[c - 'a']) {
                            q.add(pos);
                        }
                    } else {
                        q.add(new int[]{nx, ny});
                    }
                } else {
                    q.add(new int[]{nx, ny});
                }
            }
        }
        return count;
    }
}