import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        int sum = 0;
        for (int i = 0; i < N; i++) {
            int input = Integer.parseInt(br.readLine());
            int base = input / 10;
            int exponent = input % 10;
            sum += (int) Math.pow(base, exponent);
        }

        System.out.print(sum);
    }
}