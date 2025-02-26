import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int T = s.nextInt(); //테스트 데이터

        for (int i = 0; i < T; i++) {
            int M = s.nextInt();
            int N = s.nextInt();
            int x = s.nextInt();
            int y = s.nextInt();

            int k = -1;

            for (int j = x; j <= M * N; j += M) {
                if (((j - 1) % N) + 1 == y) {
                    k = j;
                    break;
                }
            }
            System.out.println(k);
        }
    }
}