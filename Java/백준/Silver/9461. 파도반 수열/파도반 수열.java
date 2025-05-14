import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static long[] padovan = new long[101];

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        padovan[1] = 1; padovan[2] = 1; padovan[3] = 1;
        for (int i = 4; i <= 100; i++) {
            padovan[i] = padovan[i - 2] + padovan[i - 3];
        }

        int T = Integer.parseInt(br.readLine()); //테스트 케이스의 개수

        for (int i = 0; i < T; i++) {
            int N = Integer.parseInt(br.readLine());
            System.out.println(padovan[N]);
        }
    }
}