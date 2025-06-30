import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine()); //라운드의 수

        int A = 100, B = 100; //창영이와 상덕이의 기본 점수
        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            int a = Integer.parseInt(input[0]);
            int b = Integer.parseInt(input[1]);
            if (a > b) {
                B -= a;
            } else if (a < b) {
                A -= b;
            }
        }

        System.out.println(A);
        System.out.print(B);
    }
}