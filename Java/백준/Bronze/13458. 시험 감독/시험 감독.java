import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine()); //시험장의 개수

        int[] A = new int[N]; //응시자의 수
        String[] input = br.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(input[i]);
        }

        String[] inputs = br.readLine().split(" ");
        int B = Integer.parseInt(inputs[0]); //감시할 수 있는 수 (총감독관)
        int C = Integer.parseInt(inputs[1]); //감시할 수 있는 수 (부감독관)

        long min = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] <= B) {
                min += 1;
            } else if (A[i] > B && (A[i] - B) % C == 0) {
                min += 1 + (A[i] - B) / C;
            } else if (A[i] > B && (A[i] - B) % C != 0) {
                min += 2 + (A[i] - B) / C;
            }
        }

        System.out.print(min);
    }
}