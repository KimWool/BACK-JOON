import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] bScore = new int[5];
        int[] aScore = new int[5];

        int sum = 0;
        for (int i = 0; i < 5; i++) {
            bScore[i] = Integer.parseInt(br.readLine());
            if (bScore[i] >= 40) {
                sum += bScore[i];
            } else {
                sum += 40;
            }
        }

        System.out.print(sum / 5);
    }
}