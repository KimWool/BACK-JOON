import java.io.*;
import java.util.*;

public class Main {
    static int R, C, T;
    static int[][] A;
    static int[][] temp;
    static int up = -1, down = -1;
    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, 1, 0, -1};

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());
        A = new int[R][C];
        for (int i = 0; i < R; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < C; j++) {
                A[i][j] = Integer.parseInt(st.nextToken());
                if (A[i][j] == -1) {
                    if (up == -1) up = i;
                    else down = i;
                }
            }
        }
        for (int t = 0; t < T; t++) {
            spread();
            clean();
        }
        int ans = 0;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (A[i][j] > 0) ans += A[i][j];
            }
        }
        System.out.println(ans);
    }

    static void spread() {
        temp = new int[R][C];
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (A[i][j] > 0) {
                    int amount = A[i][j] / 5;
                    int cnt = 0;
                    for (int d = 0; d < 4; d++) {
                        int nx = i + dx[d];
                        int ny = j + dy[d];
                        if (nx < 0 || ny < 0 || nx >= R || ny >= C || A[nx][ny] == -1) continue;
                        temp[nx][ny] += amount;
                        cnt++;
                    }
                    temp[i][j] += A[i][j] - amount * cnt;
                } else if (A[i][j] == -1) {
                    temp[i][j] = -1;
                }
            }
        }
        A = temp;
    }

    static void clean() {
        for (int i = up - 1; i > 0; i--) A[i][0] = A[i - 1][0];
        for (int j = 0; j < C - 1; j++) A[0][j] = A[0][j + 1];
        for (int i = 0; i < up; i++) A[i][C - 1] = A[i + 1][C - 1];
        for (int j = C - 1; j > 1; j--) A[up][j] = A[up][j - 1];
        A[up][1] = 0;

        for (int i = down + 1; i < R - 1; i++) A[i][0] = A[i + 1][0];
        for (int j = 0; j < C - 1; j++) A[R - 1][j] = A[R - 1][j + 1];
        for (int i = R - 1; i > down; i--) A[i][C - 1] = A[i - 1][C - 1];
        for (int j = C - 1; j > 1; j--) A[down][j] = A[down][j - 1];
        A[down][1] = 0;
    }
}