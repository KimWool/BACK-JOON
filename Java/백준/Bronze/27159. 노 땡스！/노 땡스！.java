import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        int[] cards = new int[N];
        String[] input = br.readLine().split(" ");

        for (int i = 0; i < N; i++) {
            cards[i] = Integer.parseInt(input[i]);
        }

        int score = 0;
        int groupStart = cards[0];

        for (int i = 1; i < N; i++) {
            if (cards[i] != cards[i - 1] + 1) {
                score += groupStart;
                groupStart = cards[i];
            }
        }

        score += groupStart;

        System.out.println(score);
    }
}