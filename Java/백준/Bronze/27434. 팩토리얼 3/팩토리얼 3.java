import java.io.*;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        if (N == 0) {
            System.out.print(1);
            return;
        }

        System.out.print(factorial(1, N));
    }

    public static BigInteger factorial(int start, int end) {
        if (start == end) {
            return BigInteger.valueOf(end);
        }
        return factorial(start, (start + end) / 2).multiply(factorial((start + end) / 2 + 1, end));
    }
}