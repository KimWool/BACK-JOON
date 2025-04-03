import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int[][] people = new int[15][15];

        for (int i = 0; i < people.length; i++) {
            people[0][i] = i + 1;
        }

        for (int i = 1; i < 15; i++) {
            for (int j = 0; j < 15; j++) {
                if (j == 0) {
                    people[i][j] = 1;
                } else {
                    people[i][j] = people[i][j - 1] + people[i - 1][j];
                }
            }
        }

        int T = s.nextInt(); //테스트 케이스
        for (int i = 0; i < T; i++) {
            int K = s.nextInt(); //k층
            int N = s.nextInt(); //n호
            System.out.println(people[K][N - 1]);
        }

        s.close();
    }
}