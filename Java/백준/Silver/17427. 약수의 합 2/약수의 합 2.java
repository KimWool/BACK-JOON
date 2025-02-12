import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int N = s.nextInt();
        long result = 0;

        for(int i = 1; i <= N; i++){
            result += (long) i * (N / i);
        }

        System.out.println(result);
    }
}