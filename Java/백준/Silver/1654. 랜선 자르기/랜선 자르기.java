import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int K = Integer.parseInt(input[0]); //이미 가지고 있는 랜선의 개수
        int N = Integer.parseInt(input[1]); //필요한 랜선의 개수

        int[] length = new int[K];
        long max = 0;
        for (int i = 0; i < K; i++) {
            length[i] = Integer.parseInt(br.readLine());
            if (length[i] > max) {
                max = length[i];
            }
        }

        long left = 1;
        long right = max;
        long result = 0;

        while (left <= right) {
            long mid = (left + right) / 2;
            long count = 0;
            for (int i = 0; i < K; i++) {
                count += length[i] / mid;
            }

            if (count >= N) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        System.out.print(result);
    }
}