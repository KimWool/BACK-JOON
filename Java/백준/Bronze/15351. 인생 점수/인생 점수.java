import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            int score = 0;
            String enjoy = br.readLine();
            for (int j = 0; j < enjoy.length(); j++) {
                char ch = enjoy.charAt(j);
                if (ch >= 'A' && ch <= 'Z') {
                    score += ch - 'A' + 1;
                }
            }
            if (score == 100) {
                System.out.println("PERFECT LIFE");
            } else {
                System.out.println(score);
            }
        }
    }
}