import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        try {
            String first = br.readLine();
            String second = br.readLine();
            String third = br.readLine();

            int num;

            if (isNumber(first)) {
                num = Integer.parseInt(first) + 3;
            } else if (isNumber(second)) {
                num = Integer.parseInt(second) + 2;
            } else {
                num = Integer.parseInt(third) + 1;
            }

            System.out.print(FizzBuzz(num));
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
    private static boolean isNumber(String s) {
        return !s.equals("Fizz") && !s.equals("Buzz") && !s.equals("FizzBuzz");
    }
    private static String FizzBuzz(int num) {
        if (num % 3 == 0 && num % 5 == 0) {
            return "FizzBuzz";
        } else if (num % 3 == 0) {
            return "Fizz";
        } else if (num % 5 == 0) {
            return "Buzz";
        } else {
            return Integer.toString(num);
        }
    }
}