import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int N = s.nextInt(); //N의 가장 작은 생성자 구하기

        for (int i = 1; i <= N; i++) {
            int sum = i, temp = i;
            while (temp > 0) {
                sum += temp % 10;
                temp /= 10;
            }
            if (sum == N) {
                System.out.print(i);
                return;
            }
        }

        System.out.print(0);

        s.close();
    }
}