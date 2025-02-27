import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int N = s.nextInt(); //최대 10^9까지
        int max = 0;
        double digits = 0;

        for (int i = 9; i >= 0; i--) {
            if (N - Math.pow(10, i) >= 0) {
                max = i;
                digits = (i + 1) * (N - Math.pow(10, i) + 1);
                break;
            }
        }

        for (int j = max; j > 0; j--) {
            digits += j * (Math.pow(10, j - 1) * 9);
        }

        System.out.print((long) digits);
    }
}