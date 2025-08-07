import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int A = Integer.parseInt(input[0]);
        int B = Integer.parseInt(input[1]);

        double M = (double) (B - A) / 400;
        double result = 1 / (1 + Math.pow(10, M));

        System.out.print(result);
    }
}