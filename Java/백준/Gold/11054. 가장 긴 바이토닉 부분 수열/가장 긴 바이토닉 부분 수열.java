import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] A = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }

        int[] dp_inc = new int[N];
        int[] dp_dec = new int[N];

        for (int i = 0; i < N; i++) {
            dp_inc[i] = 1;
            for (int j = 0; j < i; j++) {
                if (A[j] < A[i] && dp_inc[i] < dp_inc[j] + 1) {
                    dp_inc[i] = dp_inc[j] + 1;
                }
            }
        }

        for (int i = N - 1; i >= 0; i--) {
            dp_dec[i] = 1;
            for (int j = N - 1; j > i; j--) {
                if (A[j] < A[i] && dp_dec[i] < dp_dec[j] + 1) {
                    dp_dec[i] = dp_dec[j] + 1;
                }
            }
        }

        int result = 0;
        for (int i = 0; i < N; i++) {
            result = Math.max(result, dp_inc[i] + dp_dec[i] - 1);
        }

        System.out.println(result);
    }
}