import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int N = s.nextInt(); //참가자의 수
        int[] size = new int[6];
        for (int i = 0; i < size.length; i++) {
            size[i] = s.nextInt();
        }

        int T = s.nextInt(); //티셔츠의 묶음 수
        int P = s.nextInt(); //펜의 묶음 수

        int tShirt = 0;

        for (int j : size) {
            tShirt += j / T;
            if (j % T != 0) {
                tShirt++;
            }
        }

        System.out.println(tShirt);
        System.out.print(N / P + " " + N % P);
    }
}