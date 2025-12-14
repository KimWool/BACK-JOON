import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static final int MOD = 10007;
    static long[][] comb = new long[53][53];

    static void buildComb() {
        for (int i = 0; i <= 52; i++) {
            comb[i][0] = comb[i][i] = 1;
            for (int j = 1; j < i; j++) {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        buildComb();

        long result = 0;
        for (int k = 1; k <= Math.min(13, N / 4); k++) {
            long chooseNum = comb[13][k];
            long chooseRest = comb[52 - 4 * k][N - 4 * k];
            long ways = (chooseNum * chooseRest) % MOD;

            if (k % 2 == 1) result = (result + ways) % MOD;
            else result = (result - ways + MOD) % MOD;
        }

        System.out.println(result);
    }
}