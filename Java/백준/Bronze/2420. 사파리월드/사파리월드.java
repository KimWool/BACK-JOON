import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        long N = s.nextInt();
        long M = s.nextInt();
        
        System.out.print(Math.abs(N - M));

    }
}