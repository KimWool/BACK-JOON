import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;

        String[] input = br.readLine().split(" ");

        for (int i = 0; i < N; i++) {
            int score = Integer.parseInt(input[i]);
            if (score > max) {
                max = score;
            }
            if (score < min) {
                min = score;
            }
        }

        System.out.print(max - min);
    }
}