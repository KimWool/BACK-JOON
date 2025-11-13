import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        int[][] jewel = new int[N][2];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            jewel[i][0] = Integer.parseInt(st.nextToken());
            jewel[i][1] = Integer.parseInt(st.nextToken());
        }

        int[] c = new int[K];
        for (int i = 0; i < K; i++) {
            c[i] = Integer.parseInt(br.readLine());
        }

        Arrays.sort(jewel, (a, b) -> a[0] - b[0]);
        Arrays.sort(c);

        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        long answer = 0;
        int j = 0;

        for (int i = 0; i < K; i++) {
            while (j < N && jewel[j][0] <= c[i]) {
                pq.offer(jewel[j][1]);
                j++;
            }
            if (!pq.isEmpty()) {
                answer += pq.poll();
            }
        }

        System.out.println(answer);
    }
}