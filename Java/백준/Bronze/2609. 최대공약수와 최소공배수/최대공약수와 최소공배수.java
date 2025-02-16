import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int a = s.nextInt();
        int b = s.nextInt();

        int gcd = GCD(a, b); //최대공약수
        int lcm = LCM(a, b); //최소공배수
        
        System.out.println(gcd);
        System.out.println(lcm);
    }

    public static int GCD(int a, int b){
        if (b == 0) return a;
        int r = a % b;
        return GCD(b, r);
    }

    public static int LCM(int a, int b){
        return a * b / GCD(a, b);
    }
}