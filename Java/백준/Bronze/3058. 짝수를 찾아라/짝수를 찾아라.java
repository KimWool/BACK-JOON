import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine()); //입력 데이터의 수

        for (int i = 0; i < T; i++) {
            String[] input = br.readLine().split(" ");

            int sum = 0;
            int min = Integer.MAX_VALUE;

            for (String s : input) {
                if (Integer.parseInt(s) % 2 == 0) {
                    sum += Integer.parseInt(s);
                    min = Math.min(min, Integer.parseInt(s));
                }
            }

            System.out.println(sum + " " + min);
        }
    }
}