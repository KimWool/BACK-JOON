import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]); //총 N문제 이상 해결하려면
        int M = Integer.parseInt(input[1]); //하루에 M문제씩
        int K = Integer.parseInt(input[2]); //최소 K일은 더 풀어야 해요

        int min, max; //최솟값과 최댓값
        min = Math.max((N - M * K), 0);
        max = N - M * (K - 1) - 1;

        System.out.print(min + " " + max);
    }
}