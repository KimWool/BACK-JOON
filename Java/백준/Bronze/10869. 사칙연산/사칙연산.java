import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int A = s.nextInt();
        int B = s.nextInt();

        int sum = A + B;
        int min = A - B;
        int mul = A * B;
        int div = A / B;
        int mod = A % B;
        
        System.out.println(sum);
        System.out.println(min);
        System.out.println(mul);
        System.out.println(div);
        System.out.println(mod);

    }
}