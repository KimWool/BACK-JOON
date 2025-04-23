import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int K;

        try {
            K = Integer.parseInt(br.readLine());
            int[] numbers = new int[K];
            int sum = 0;
            for (int i = 0; i < K; i++) {
                numbers[i] = Integer.parseInt(br.readLine());
                if (numbers[i] == 0) {
                    for (int j = i; j >= 0; j--) {
                        if (numbers[j] != 0) {
                            numbers[j] = 0;
                            break;
                        }
                    }
                }
            }
            for (int i = 0; i < K; i++) {
                sum += numbers[i];
            }
            System.out.print(sum);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}