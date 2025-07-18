import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int S = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());
        int L = Integer.parseInt(br.readLine());

        int happiness = S + 2 * M + 3 * L;
        if (happiness >= 10) {
            System.out.print("happy");
        } else {
            System.out.print("sad");
        }
    }
}