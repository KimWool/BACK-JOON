import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String ISBN = br.readLine();

        int result = 0;
        int missingIndex = -1;

        for (int i = 0; i < ISBN.length(); i++) {
            char c = ISBN.charAt(i);
            if (Character.isDigit(c)) {
                int digit = c - '0';
                int weight = (i % 2 == 0) ? 1 : 3;
                result += digit * weight;
            } else {
                missingIndex = i;
            }
        }

        for (int i = 0; i <= 9; i++) {
            int weight = (missingIndex % 2 == 0) ? 1 : 3;
            int total = result + i * weight;
            if (total % 10 == 0) {
                System.out.print(i);
                return;
            }
        }
    }
}