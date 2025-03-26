import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int T = s.nextInt(); //테스트 케이스의 개수
        s.nextLine();

        for (int i = 0; i < T; i++) {
            int grade = 0;
            int total = 0;
            String errata = s.nextLine(); //OX 퀴즈의 결과
            for (int j = 0; j < errata.length(); j++) {
                if (errata.charAt(j) == 'O') {
                    grade++;
                    total += grade;
                } else if (errata.charAt(j) == 'X') {
                    grade = 0;
                }
            }
            System.out.println(total);
        }

        s.close();
    }
}