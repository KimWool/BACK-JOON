import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int number = Integer.parseInt(br.readLine());
        for (int i = 0; i < number; i++) {
            int n = Integer.parseInt(br.readLine());
            System.out.println(n + " " + n);
        }
    }
}