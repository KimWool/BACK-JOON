import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] A = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }

        int[] dp = new int[N];
        int[] index = new int[N];
        int length = 0;

        dp[0] = A[0];
        index[0] = 0;
        length = 1;

        for (int i = 1; i < N; i++) {
            if (A[i] > dp[length - 1]) {
                dp[length] = A[i];
                index[i] = length;
                length++;
            } else {
                int pos = Arrays.binarySearch(dp, 0, length, A[i]);
                if (pos < 0) pos = -pos - 1;
                dp[pos] = A[i];
                index[i] = pos;
            }
        }

        StringBuilder sb = new StringBuilder();
        sb.append(length).append("\n");

        Stack<Integer> stack = new Stack<>();
        for (int i = N - 1; i >= 0; i--) {
            if (index[i] == length - 1) {
                stack.push(A[i]);
                length--;
            }
        }

        while (!stack.isEmpty()) {
            sb.append(stack.pop()).append(" ");
        }

        System.out.println(sb);
    }
}