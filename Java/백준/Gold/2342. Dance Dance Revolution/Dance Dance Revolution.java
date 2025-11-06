import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    static int[][][] dp;
    static int[] arr;
    static int len = 0;
    static final int INF = 1000000000;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        arr = new int[100001];
        StringTokenizer st = new StringTokenizer(br.readLine());
        int idx = 0;
        while (true) {
            int n = Integer.parseInt(st.nextToken());
            if (n == 0) break;
            arr[idx++] = n;
        }
        len = idx;
        dp = new int[len + 1][5][5];

        for (int i = 0; i <= len; i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5; k++) {
                    dp[i][j][k] = INF;
                }
            }
        }

        dp[0][0][0] = 0;

        for (int i = 0; i < len; i++) {
            int next = arr[i];
            for (int l = 0; l < 5; l++) {
                for (int r = 0; r < 5; r++) {
                    int now = dp[i][l][r];
                    if (now == INF) continue;
                    dp[i + 1][next][r] = Math.min(dp[i + 1][next][r], now + getCost(l, next));
                    dp[i + 1][l][next] = Math.min(dp[i + 1][l][next], now + getCost(r, next));
                }
            }
        }

        int answer = INF;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                answer = Math.min(answer, dp[len][i][j]);
            }
        }

        System.out.println(answer);
    }

    static int getCost(int from, int to) {
        if (from == 0) return 2;
        if (from == to) return 1;
        if (Math.abs(from - to) == 2) return 4;
        return 3;
    }
}