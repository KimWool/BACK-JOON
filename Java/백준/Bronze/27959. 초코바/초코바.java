import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]); //100원 동전 개수
        int M = Integer.parseInt(input[1]); //초코바의 가격

        int money = N * 100;
        if (money >= M) {
            System.out.print("Yes");
        } else {
            System.out.print("No");
        }
    }
}