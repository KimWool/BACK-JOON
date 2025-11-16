import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static long countOnes(long x) {
        long count = 0;
        long bit = 1;

        while (bit <= x) {
            long totalPairs = x / (bit * 2);
            long remainder = x % (bit * 2);

            count += totalPairs * bit;
            if (remainder >= bit) {
                count += remainder - bit + 1;
            }

            bit <<= 1;
        }

        return count;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        long A = Long.parseLong(input[0]);
        long B = Long.parseLong(input[1]);

        System.out.println(countOnes(B) - countOnes(A - 1));
    }
}