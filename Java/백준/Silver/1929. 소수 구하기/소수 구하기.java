import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int M = s.nextInt();
        int N = s.nextInt();

        boolean[] prime = new boolean[N + 1]; //0부터 N까지의 소수 여부를 판별
        prime[1] = false;
        for (int i = 2; i <= N; i++) {
            prime[i] = true;
        }

        for (int i = 2; i * i <= N; i++) {
            if (!prime[i]) continue; //이미 판별된 경우에는 넘어간다.
            for (int j = 2; i * j <= N; j++) {
                prime[i * j] = false;
            }
        }

        for (int i = M; i <= N; i++) {
            if (prime[i]){
                System.out.println(i);
            }
        }

    }
}