import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int A = s.nextInt();
        int B = s.nextInt();
        int C = s.nextInt();

        int result = A * B * C;
        int[] counts = new int[10];

        while (result != 0) {
            int digit = result % 10;
            counts[digit]++;
            result = result / 10;
        }

        for (int i = 0; i < 10; i++) {
            System.out.println(counts[i]);
        }

        s.close();
    }
}