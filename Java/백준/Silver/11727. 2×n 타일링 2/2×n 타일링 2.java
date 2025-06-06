import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        long[] arr = new long[1001];
        arr[1] = 1; arr[2] = 3;

        int n = Integer.parseInt(br.readLine());
        for(int i = 3; i <= n; i++){
            arr[i] = (arr[i - 1] + 2 * arr[i - 2]) % 10007;
        }

        System.out.print(arr[n]);
    }
}