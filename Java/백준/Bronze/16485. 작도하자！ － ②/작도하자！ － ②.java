import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int c = Integer.parseInt(input[0]);
        int b = Integer.parseInt(input[1]);

        float result = (float) c / b;
        System.out.print(result);
    }
}