import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int N = s.nextInt(); //N번째 영화의 제목

        int num = 666; //제일 작은 종말의 수
        int count = 1;

        while (count != N) {
            num++;
            if (String.valueOf(num).contains("666")) {
                count++;
            }
        }

        System.out.print(num);
    }
}