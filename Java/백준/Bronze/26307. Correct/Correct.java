import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int Hour = Integer.parseInt(input[0]);
        int Min = Integer.parseInt(input[1]);

        int result = (Hour - 9) * 60 + Min;
        System.out.print(result);
    }
}