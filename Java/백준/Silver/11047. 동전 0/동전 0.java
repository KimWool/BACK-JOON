import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N, K;
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]); //가지고 있는 동전의 종류
        K = Integer.parseInt(input[1]); //만들어야 하는 가치

        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        int count = 0;
        for (int i = N - 1; i >= 0; i--) {
            count += (K / arr[i]);
            K %= arr[i];
        }

        System.out.print(count);
    }
}