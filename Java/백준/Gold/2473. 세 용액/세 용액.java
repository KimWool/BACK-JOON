import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        long[] arr = new long[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Long.parseLong(st.nextToken());
        }

        Arrays.sort(arr);

        long minSum = Long.MAX_VALUE;
        long x = 0, y = 0, z = 0;

        for (int i = 0; i < N - 2; i++) {
            int left = i + 1;
            int right = N - 1;

            while (left < right) {
                long sum = arr[i] + arr[left] + arr[right];
                if (Math.abs(sum) < minSum) {
                    minSum = Math.abs(sum);
                    x = arr[i];
                    y = arr[left];
                    z = arr[right];
                }

                if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        System.out.println(x + " " + y + " " + z);
    }
}