import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int N = s.nextInt();
        String str = "*";

        for (int i = 1; i <= N; i++) {
            System.out.println(str.repeat(i));
        }

    }
}