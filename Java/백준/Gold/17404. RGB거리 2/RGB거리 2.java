import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] cost = new int[n + 1][3];
        StringTokenizer st;

        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            cost[i][0] = Integer.parseInt(st.nextToken());
            cost[i][1] = Integer.parseInt(st.nextToken());
            cost[i][2] = Integer.parseInt(st.nextToken());
        }

        final int INF = 1000 * 1000;
        int result = INF;

        for (int first = 0; first < 3; first++) {
            int[][] dp = new int[n + 1][3];

            for (int i = 0; i < 3; i++) {
                if (i == first) dp[1][i] = cost[1][i];
                else dp[1][i] = INF;
            }

            for (int i = 2; i <= n; i++) {
                dp[i][0] = Math.min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
                dp[i][1] = Math.min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
                dp[i][2] = Math.min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
            }

            for (int last = 0; last < 3; last++) {
                if (last == first) continue;
                result = Math.min(result, dp[n][last]);
            }
        }

        System.out.println(result);
    }
}