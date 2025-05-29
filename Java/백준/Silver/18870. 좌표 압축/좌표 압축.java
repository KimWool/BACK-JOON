import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine()); //X의 개수
        int[] X = new int[N];
        int[] Y;

        String[] input = br.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            X[i] = Integer.parseInt(input[i]);
        }

        Y = X.clone();
        Arrays.sort(Y);

        HashMap<Integer, Integer> map = new HashMap<>();
        int rank = 0;
        for (int i = 0; i < N; i++) {
            if (!map.containsKey(Y[i])) {
                map.put(Y[i], rank++);
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < N; i++) {
            sb.append(map.get(X[i])).append(" ");
        }

        System.out.print(sb.toString());
    }
}