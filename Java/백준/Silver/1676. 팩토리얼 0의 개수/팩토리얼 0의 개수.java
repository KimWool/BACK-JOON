import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int N = s.nextInt(); //0부터 500까지의 정수

        int count = 0;
        for (int i = 5; i <=N; i *= 5){
            count += N / i;
        }

        System.out.print(count);
    }
}