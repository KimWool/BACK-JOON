import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int number = 1;
        String input;

        while (true) {
            input = br.readLine();
            if (input.equals("0")) {
                break;
            }
            System.out.println("Case " + number + ": Sorting... done!");
            number++;
        }
    }
}