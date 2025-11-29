import java.io.*;
import java.util.*;

public class Main {
    static int R, C, M;
    static Shark[][] map;
    static int[] dx = {0, -1, 1, 0, 0};
    static int[] dy = {0, 0, 0, 1, -1};

    static class Shark {
        int r, c, s, d, z;
        Shark(int r, int c, int s, int d, int z) {
            this.r = r;
            this.c = c;
            this.s = s;
            this.d = d;
            this.z = z;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        map = new Shark[R + 1][C + 1];
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            int s = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());
            int z = Integer.parseInt(st.nextToken());
            map[r][c] = new Shark(r, c, s, d, z);
        }

        int ans = 0;
        for (int king = 1; king <= C; king++) {
            for (int i = 1; i <= R; i++) {
                if (map[i][king] != null) {
                    ans += map[i][king].z;
                    map[i][king] = null;
                    break;
                }
            }
            moveSharks();
        }
        System.out.println(ans);
    }

    static void moveSharks() {
        Shark[][] newMap = new Shark[R + 1][C + 1];
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                if (map[i][j] != null) {
                    Shark shark = map[i][j];
                    int s = shark.s;
                    int d = shark.d;
                    int x = shark.r;
                    int y = shark.c;

                    if (d == 1 || d == 2) s %= (2 * (R - 1));
                    else s %= (2 * (C - 1));

                    for (int m = 0; m < s; m++) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];

                        if (nx < 1 || nx > R || ny < 1 || ny > C) {
                            if (d == 1) d = 2;
                            else if (d == 2) d = 1;
                            else if (d == 3) d = 4;
                            else if (d == 4) d = 3;
                            nx = x + dx[d];
                            ny = y + dy[d];
                        }
                        x = nx;
                        y = ny;
                    }

                    if (newMap[x][y] == null || newMap[x][y].z < shark.z) {
                        newMap[x][y] = new Shark(x, y, shark.s, d, shark.z);
                    }
                }
            }
        }
        map = newMap;
    }
}