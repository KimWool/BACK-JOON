import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int T = s.nextInt(); //T개의 테스트 케이스
        for (int i = 0; i < T; i++) {
            int H = s.nextInt(); //호텔의 층 수
            int W = s.nextInt(); //각 층의 방 수
            int N = s.nextInt(); //몇 번째 손님?

            int floor = N % H == 0 ? H : N % H;
            int number = (N - 1) / H + 1;

            System.out.printf("%d%02d\n", floor, number);
        }

        s.close();
    }
}