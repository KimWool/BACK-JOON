import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int A = Integer.parseInt(input[0]);
        int B = Integer.parseInt(input[1]);
        int C = Integer.parseInt(input[2]);

        int max = A * B * C;

        //홀수만 포함된 모든 조합의 곱 중 최댓값 찾기
        int result = 0;

        if (A % 2 == 1) result = Math.max(result, A);
        if (B % 2 == 1) result = Math.max(result, B);
        if (C % 2 == 1) result = Math.max(result, C);

        if (A % 2 == 1 && B % 2 == 1) result = Math.max(result, A * B);
        if (B % 2 == 1 && C % 2 == 1) result = Math.max(result, B * C);
        if (C % 2 == 1 && A % 2 == 1) result = Math.max(result, C * A);

        if (A % 2 == 1 && B % 2 == 1 && C % 2 == 1) result = Math.max(result, A * B * C);

        if (result == 0) { //모두 짝수인 경우
            System.out.print(max);
        } else {
            System.out.print(result);
        }
    }
}