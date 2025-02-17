import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int cnt = 0;
        int num = s.nextInt();

        for (int i = 0; i < num; i++) {
            int N = s.nextInt();
            boolean isPrime = true;
            if (N < 2) {
                isPrime = false;
            } else {
                for (int j = 2; j < N; j++) {
                    if (N % j == 0){ //소수가 아닌 경우 반복문을 빠져나온다.
                        isPrime = false;
                        break;
                    }
                }
            }
            if (isPrime) {
                cnt++;
            }
        }
        System.out.println(cnt);
    }
}