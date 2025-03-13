import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int N = s.nextInt();
        for (int i = 1; i <= N; i++) {
            //N - i만큼 공백을 입력하고, i만큼 *를 입력
            for (int j = 1; j <= N - i; j++) {
                System.out.print(" ");
            }
            for (int j = 1; j <= i; j++) {
                System.out.print("*");
            }
            System.out.println();
        }

    }
}