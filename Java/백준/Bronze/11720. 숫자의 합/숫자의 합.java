import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int N = s.nextInt();
        String numbers = s.next();
        int sum = 0;

        for (int i = 0; i < N; i++) {
            int number = numbers.charAt(i) - '0';
            sum += number;
        }

        System.out.print(sum);

    }
}