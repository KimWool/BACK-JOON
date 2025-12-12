import java.io.*;
import java.util.*;

public class Main {
    static final int MOD = 1_000_000_007;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] capsaicin = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            capsaicin[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(capsaicin);
        long[] pow2 = new long[n];
        pow2[0] = 1;
        for (int i = 1; i < n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        long result = 0;
        for (int i = 0; i < n; i++) {
            long add = (capsaicin[i] * pow2[i]) % MOD;
            long sub = (capsaicin[i] * pow2[n - i - 1]) % MOD;
            result = (result + add - sub + MOD) % MOD;
        }

        System.out.println(result);
    }
}