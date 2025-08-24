import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]); //바구니의 개수
        int M = Integer.parseInt(input[1]); //공을 바꾸는 횟수

        int[] basket = new int[N];
        for (int n = 0; n < N; n++) {
            basket[n] = n + 1;
        }

        for (int n = 0; n < M; n++) {
            String[] change = br.readLine().split(" ");
            int i = Integer.parseInt(change[0]);
            int j = Integer.parseInt(change[1]);

            int temp = basket[i - 1];
            basket[i - 1] = basket[j - 1];
            basket[j - 1] = temp;
        }

        for (int i = 0; i < N; i++) {
            System.out.print(basket[i] + " ");
        }
    }
}