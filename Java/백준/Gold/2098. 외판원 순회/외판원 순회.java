import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int[][] W;
    static int[][] dp;
    static final int INF = 10000000;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        W = new int[N][N];
        dp = new int[N][1 << N];

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                W[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 0; i < N; i++) {
            Arrays.fill(dp[i], -1);
        }

        System.out.println(tsp(0, 1));
    }

    static int tsp(int current, int visited) {
        if (visited == (1 << N) - 1) {
            if (W[current][0] == 0) return INF;
            return W[current][0];
        }

        if (dp[current][visited] != -1) return dp[current][visited];

        dp[current][visited] = INF;

        for (int i = 0; i < N; i++) {
            if ((visited & (1 << i)) == 0 && W[current][i] != 0) {
                dp[current][visited] = Math.min(dp[current][visited],
                        tsp(i, visited | (1 << i)) + W[current][i]);
            }
        }

        return dp[current][visited];
    }
}