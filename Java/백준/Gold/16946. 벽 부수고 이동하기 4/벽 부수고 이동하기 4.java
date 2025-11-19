import java.io.*;
import java.util.*;

public class Main {
    static int n, m;
    static int[][] map;
    static int[][] group;
    static int[] groupSize;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        map = new int[n][m];
        group = new int[n][m];

        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < m; j++) {
                map[i][j] = s.charAt(j) - '0';
            }
        }

        int groupId = 1;
        groupSize = new int[n * m + 1];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 0 && group[i][j] == 0) {
                    bfs(i, j, groupId);
                    groupId++;
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 1) {
                    Set<Integer> adjacentGroups = new HashSet<>();
                    int sum = 1;
                    for (int d = 0; d < 4; d++) {
                        int nx = i + dx[d];
                        int ny = j + dy[d];
                        if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                            int gId = group[nx][ny];
                            if (gId != 0 && !adjacentGroups.contains(gId)) {
                                adjacentGroups.add(gId);
                                sum += groupSize[gId];
                            }
                        }
                    }
                    sb.append(sum % 10);
                } else {
                    sb.append(0);
                }
            }
            sb.append('\n');
        }

        System.out.print(sb);
    }

    static void bfs(int x, int y, int id) {
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{x, y});
        group[x][y] = id;
        int count = 1;

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            for (int d = 0; d < 4; d++) {
                int nx = cur[0] + dx[d];
                int ny = cur[1] + dy[d];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    if (map[nx][ny] == 0 && group[nx][ny] == 0) {
                        group[nx][ny] = id;
                        q.add(new int[]{nx, ny});
                        count++;
                    }
                }
            }
        }

        groupSize[id] = count;
    }
}