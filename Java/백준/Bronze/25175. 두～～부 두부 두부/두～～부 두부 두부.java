import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]); //게임을 하는 사람의 수
        int M = Integer.parseInt(input[1]); //현재 차례인 사람의 번호 (3모)
        int K = Integer.parseInt(input[2]); //부른 두부의 모 수를 나타내는 정수

        int distance = K - 3;
        int next = ((M - 1 + distance) % N + N) % N + 1;

        System.out.print(next);
    }
}