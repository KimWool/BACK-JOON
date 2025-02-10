import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        while (s.hasNextInt()){
            int n = s.nextInt();
            int remainder = 0;

            for (int i = 1; i <= n; i++) {
                remainder = (remainder * 10 + 1) % n;

                if (remainder == 0){
                    System.out.println(i);
                    break;
                }
            }
        }
    }
}