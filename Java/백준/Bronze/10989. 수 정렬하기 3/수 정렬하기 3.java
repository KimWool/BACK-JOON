import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        try {
            int N = Integer.parseInt(br.readLine());
            int[] count = new int[10001]; //각 수는 10000보다 작거나 같은 자연수

            for (int i = 0; i < N; i++) {
                count[Integer.parseInt(br.readLine())]++;
            }

            for (int i = 1; i < count.length; i++) {
                while (count[i] > 0) {
                    sb.append(i).append('\n');
                    count[i]--;
                }
            }

            System.out.println(sb);
            br.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}