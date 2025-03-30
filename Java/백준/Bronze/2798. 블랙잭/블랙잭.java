import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int N = s.nextInt(); //카드의 개수
        int M = s.nextInt(); //카드의 총 합은 M을 넘지 말아야 함

        int[] cards = new int[N];
        for (int i = 0; i < N; i++) {
            cards[i] = s.nextInt();
        }

        int max = 0;
        for (int i = 0; i < N - 2; i++) {
            for (int j = i + 1; j < N - 1; j++) {
                for (int k = j + 1; k < N; k++) {
                    int sum = cards[i] + cards[j] + cards[k];
                    if (sum > max && sum <= M) {
                        max = sum;
                    }
                }
            }
        }

        System.out.print(max);

        s.close();
    }
}