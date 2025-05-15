import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]); //수의 개수
        int M = Integer.parseInt(input[1]); //구해야 하는 횟수

        int[] arr = new int[N + 1];
        String[] inputArr = br.readLine().split(" ");
        for(int i = 1; i <= N; i++){
            arr[i] = Integer.parseInt(inputArr[i - 1]);
        }

        int[] prefixSum = new int[N + 1];
        for (int i = 1; i <= N; i++){
            prefixSum[i] = prefixSum[i - 1] + arr[i];
        }

        for (int i = 0; i < M; i++) {
            String[] range = br.readLine().split(" ");
            int start = Integer.parseInt(range[0]);
            int end = Integer.parseInt(range[1]);

            System.out.println(prefixSum[end] - prefixSum[start - 1]);
        }
    }
}