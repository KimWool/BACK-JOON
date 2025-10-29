import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] A = new int[N + 1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }

        boolean[][] dp = new boolean[N + 1][N + 1];

        for (int i = 1; i <= N; i++) {
            dp[i][i] = true;
        }

        for (int i = 1; i < N; i++) {
            if (A[i] == A[i + 1]) {
                dp[i][i + 1] = true;
            }
        }

        for (int len = 3; len <= N; len++) {
            for (int s = 1; s <= N - len + 1; s++) {
                int e = s + len - 1;
                if (A[s] == A[e] && dp[s + 1][e - 1]) {
                    dp[s][e] = true;
                }
            }
        }

        int M = Integer.parseInt(br.readLine());
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int S = Integer.parseInt(st.nextToken());
            int E = Integer.parseInt(st.nextToken());
            if (dp[S][E]) {
                bw.write("1\n");
            } else {
                bw.write("0\n");
            }
        }
        bw.flush();
    }
}