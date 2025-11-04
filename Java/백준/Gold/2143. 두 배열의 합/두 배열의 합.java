import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long T = Long.parseLong(br.readLine());
        int n = Integer.parseInt(br.readLine());
        int[] A = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }

        int m = Integer.parseInt(br.readLine());
        int[] B = new int[m];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < m; i++) {
            B[i] = Integer.parseInt(st.nextToken());
        }

        List<Long> sumA = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            long sum = 0;
            for(int j = i; j < n; j++) {
                sum += A[j];
                sumA.add(sum);
            }
        }

        Map<Long, Integer> mapA = new HashMap<>();
        for(long a : sumA) {
            mapA.put(a, mapA.getOrDefault(a, 0) + 1);
        }

        long result = 0;
        for(int i = 0; i < m; i++) {
            long sum = 0;
            for(int j = i; j < m; j++) {
                sum += B[j];
                long target = T - sum;
                result += mapA.getOrDefault(target, 0);
            }
        }

        System.out.println(result);
    }
}