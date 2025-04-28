import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        try {
            int n = Integer.parseInt(br.readLine());
            int[] level = new int[n];
            for (int i = 0; i < n; i++) {
                level[i] = Integer.parseInt(br.readLine());
            }

            Arrays.sort(level);

            int cut = (int) Math.round(n * 0.15);
            int sum = 0;
            for (int i = cut; i < n - cut; i++) {
                sum += level[i];
            }

            int average = (n - 2 * cut) == 0 ? 0 : (int) Math.round((double) sum / (n - 2 * cut));
            System.out.print(average);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

    }
}