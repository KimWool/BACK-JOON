import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] minusSplits = br.readLine().split("-");

        int result = 0;
        result += sumOfTokens(minusSplits[0]);

        for(int i = 1; i < minusSplits.length; i++){
            result -= sumOfTokens(minusSplits[i]);
        }

        System.out.print(result);
    }

    public static int sumOfTokens(String part) {
        String[] tokens = part.split("\\+");
        int sum = 0;
        for (String token : tokens) {
            sum += Integer.parseInt(token);
        }
        return sum;
    }
}