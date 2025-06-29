import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);

        int[][] fish = new int[N][M];
        for (int i = 0; i < N; i++) {
            String line = br.readLine();
            for (int j = 0; j < M; j++) {
                fish[i][j] = Character.getNumericValue(line.charAt(j));
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = M - 1; j >= 0; j--) {
                System.out.print(fish[i][j]);
            }
            System.out.println();
        }
    }
}