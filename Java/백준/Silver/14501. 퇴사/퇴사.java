import java.util.Scanner;

public class Main {

    static int N;
    static int[] T, P;
    static int maxProfit = 0;

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        N = s.nextInt(); //N+1일 후에 퇴사

        T = new int[N + 1]; //상담을 하는데 필요한 기간
        P = new int[N + 1]; //상담했을 때 받을 수 있는 금액
        for (int i = 1; i <= N; i++) {
            T[i] = s.nextInt();
            P[i] = s.nextInt();
        }

        backtrack(1, 0);
        System.out.println(maxProfit);
    }

    public static void backtrack(int date, int profit) {
        if (date == N + 1) {
            maxProfit = Math.max(maxProfit, profit);
            return;
        }
        if (date + T[date] <= N + 1) {
            backtrack(date + T[date], profit + P[date]);
        }
        backtrack(date + 1, profit);
    }
}