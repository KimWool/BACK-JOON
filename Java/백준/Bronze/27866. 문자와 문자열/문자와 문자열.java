import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        String S = s.nextLine();
        int i = s.nextInt() - 1;

        System.out.print(S.charAt(i));

    }
}