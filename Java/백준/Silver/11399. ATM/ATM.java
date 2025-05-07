import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine()); //사람의 수
        int[] P = new int[N];

        String[] input = br.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            P[i] = Integer.parseInt(input[i]); //돈을 인출하는 데 걸리는 시간
        }

        Arrays.sort(P);

        int sum = 0;
        int time = 0;
        for (int i = 0; i < N; i++) {
            time += P[i];
            sum += time;
        }

        System.out.print(sum);
    }
}