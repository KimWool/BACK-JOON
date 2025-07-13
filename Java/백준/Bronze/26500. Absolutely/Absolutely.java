import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine()); //데이터셋 개수

        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            double a = Double.parseDouble(input[0]);
            double b = Double.parseDouble(input[1]);

            double result = Math.abs(a - b);
            System.out.printf("%.1f\n", Math.round(result * 10) / 10.0);
        }
    }
}