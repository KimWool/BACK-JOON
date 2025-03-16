import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int[] numbers = new int[9];
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < numbers.length; i++) {
            numbers[i] = s.nextInt();
            if (numbers[i] > max) {
                max = numbers[i];
            }
        }

        for (int i = 0; i < numbers.length; i++) {
            if (numbers[i] == max) {
                System.out.println(numbers[i]);
                System.out.print(i + 1);
                break;
            }
        }

        s.close();
    }
}