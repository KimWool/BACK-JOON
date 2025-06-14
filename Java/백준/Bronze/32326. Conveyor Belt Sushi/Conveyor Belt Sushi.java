import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] plates = new int[3];
        for (int i = 0; i < 3; i++) {
            plates[i] = Integer.parseInt(br.readLine());
        }

        int result = 0;
        int[] costs = {3, 4, 5};
        for (int i = 0; i < 3; i++) {
            result += plates[i] * costs[i];
        }

        System.out.print(result);
    }
}