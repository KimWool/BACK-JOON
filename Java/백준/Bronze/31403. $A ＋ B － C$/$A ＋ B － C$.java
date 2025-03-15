import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int A = s.nextInt();
        int B = s.nextInt();
        int C = s.nextInt();

        String sum = "";
        sum += A;
        sum += B;
        int result = Integer.parseInt(sum);

        System.out.println(A + B - C);
        System.out.print(result - C);
        
        s.close();
    }
}