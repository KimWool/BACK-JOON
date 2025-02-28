import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int T = s.nextInt(); //테스트 케이스의 개수

        int[] sum = new int[12]; //1~11까지의 양수
        sum[1] = 1;
        sum[2] = 2;
        sum[3] = 4;

        for (int i = 4; i < 11; i++) {
            sum[i] = sum[i - 1] + sum[i - 2] + sum[i - 3];
        }

        for (int i = 0; i < T; i++) {
            int n = s.nextInt();
            System.out.println(sum[n]);
        }

    }
}