import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine()); //공부 계획의 수

        int sum = 0;
        String[] input = br.readLine().split(" ");

        for (int i = 0; i < N; i++) {
            int study = Integer.parseInt(input[i]);
            sum += study;
        }

        sum += 8 * (N - 1);

        int day = sum / 24;
        int hour = sum % 24;

        System.out.print(day + " " + hour);
    }
}