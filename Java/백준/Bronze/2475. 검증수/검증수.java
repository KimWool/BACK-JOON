import java.util.Scanner;

public class Main {
public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int[] numbers = new int[5];
        double clarify = 0;
        for (int i = 0; i < 5; i++) {
            numbers[i] = s.nextInt();
            clarify += Math.pow(numbers[i], 2);
        }

        System.out.print((int) clarify % 10);
    }
}