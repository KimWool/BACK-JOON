import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        while(true) {
            int[] n = new int[3];
            for(int i = 0; i < 3; i++) {
                n[i] = s.nextInt();
            }
            Arrays.sort(n);
            if(n[0] == 0 && n[1] == 0 && n[2] == 0) break;
            if(Math.pow(n[0], 2) + Math.pow(n[1], 2) == Math.pow(n[2], 2)){
                System.out.println("right");
            } else {
                System.out.println("wrong");
            }
        }
    }
}