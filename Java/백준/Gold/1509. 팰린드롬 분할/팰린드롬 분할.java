import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        int n = s.length();

        boolean[][] isPalindrome = new boolean[n][n];
        for (int i = 0; i < n; i++) {
            isPalindrome[i][i] = true;
        }
        for (int i = 0; i < n - 1; i++) {
            isPalindrome[i][i + 1] = (s.charAt(i) == s.charAt(i + 1));
        }
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s.charAt(i) == s.charAt(j) && isPalindrome[i + 1][j - 1]) {
                    isPalindrome[i][j] = true;
                }
            }
        }

        int[] dp = new int[n];
        for (int i = 0; i < n; i++) {
            dp[i] = i + 1;
            for (int j = 0; j <= i; j++) {
                if (isPalindrome[j][i]) {
                    if (j == 0) {
                        dp[i] = 1;
                    } else {
                        dp[i] = Math.min(dp[i], dp[j - 1] + 1);
                    }
                }
            }
        }

        System.out.println(dp[n - 1]);
    }
}