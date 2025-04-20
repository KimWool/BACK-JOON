import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        try {
            int N = Integer.parseInt(br.readLine()); //설탕 Nkg

            int[] dp = new int[N + 1];
            for (int i = 1; i <= N; i++) {
                dp[i] = Integer.MAX_VALUE;
            }
            dp[0] = 0;

            for (int i = 1; i <= N; i++) {
                if (i >= 3 && dp[i - 3] != Integer.MAX_VALUE) {
                    dp[i] = Math.min(dp[i], dp[i - 3] + 1);
                }
                if (i >= 5 && dp[i - 5] != Integer.MAX_VALUE) {
                    dp[i] = Math.min(dp[i], dp[i - 5] + 1);
                }
            }

            if (dp[N] == Integer.MAX_VALUE) {
                System.out.print(-1);
            } else {
                System.out.print(dp[N]);
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}