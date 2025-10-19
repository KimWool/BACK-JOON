import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static final long MOD = 1000000007L;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long n = Long.parseLong(br.readLine());
        System.out.println(fib(n)[0][1]);
    }

    static long[][] fib(long n) {
        if (n == 0) {
            return new long[][]{{0, 0}, {0, 0}};
        }
        if (n == 1) {
            return new long[][]{{1, 1}, {1, 0}};
        }

        long[][] half = fib(n / 2);
        long[][] result = multiply(half, half);

        if (n % 2 == 1) {
            long[][] base = {{1, 1}, {1, 0}};
            result = multiply(result, base);
        }

        return result;
    }

    static long[][] multiply(long[][] a, long[][] b) {
        long[][] result = new long[2][2];
        result[0][0] = (a[0][0] * b[0][0] % MOD + a[0][1] * b[1][0] % MOD) % MOD;
        result[0][1] = (a[0][0] * b[0][1] % MOD + a[0][1] * b[1][1] % MOD) % MOD;
        result[1][0] = (a[1][0] * b[0][0] % MOD + a[1][1] * b[1][0] % MOD) % MOD;
        result[1][1] = (a[1][0] * b[0][1] % MOD + a[1][1] * b[1][1] % MOD) % MOD;
        return result;
    }
}