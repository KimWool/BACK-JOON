import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        List<Integer> primes = new ArrayList<>();
        boolean[] isPrime = new boolean[n + 1];
        Arrays.fill(isPrime, true);
        isPrime[0] = false;
        isPrime[1] = false;

        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                primes.add(i);
                for (int j = i * 2; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        int count = 0;
        int left = 0;
        int right = 0;
        int sum = 0;

        while (true) {
            if (sum >= n) {
                if (sum == n) {
                    count++;
                }
                sum -= primes.get(left++);
            } else {
                if (right == primes.size()) {
                    break;
                }
                sum += primes.get(right++);
            }
        }

        System.out.println(count);
    }
}