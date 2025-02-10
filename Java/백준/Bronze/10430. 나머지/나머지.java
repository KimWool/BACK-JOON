import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        int A, B, C;
        int a1, a2, a3, a4;

        Scanner s = new Scanner(System.in);
        A = s.nextInt();
        B = s.nextInt();
        C = s.nextInt();

        a1 = (A+B)%C;
        a2 = ((A%C)+(B%C))%C;
        a3 = (A*B)%C;
        a4 = ((A%C)*(B%C))%C;

        System.out.println(a1 + " " + a2 + " " + a3 + " " + a4);
    }
}