import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int T = s.nextInt(); //테스트 케이스의 개수
        for (int i = 0; i < T; i++) {
            int R = s.nextInt(); //반복 횟수
            String S = s.nextLine();
            for (int j = 1; j < S.length(); j++) {
                for (int k = 0; k < R; k++) {
                    System.out.print(S.charAt(j));
                }
            }
            System.out.println();
        }

        s.close();
    }
}