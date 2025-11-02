import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int K = Integer.parseInt(st.nextToken());

            int[] D = new int[N + 1];
            int[] indegree = new int[N + 1];
            List<Integer>[] graph = new ArrayList[N + 1];
            for (int i = 1; i <= N; i++) graph[i] = new ArrayList<>();

            st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= N; i++) D[i] = Integer.parseInt(st.nextToken());

            for (int i = 0; i < K; i++) {
                st = new StringTokenizer(br.readLine());
                int X = Integer.parseInt(st.nextToken());
                int Y = Integer.parseInt(st.nextToken());
                graph[X].add(Y);
                indegree[Y]++;
            }

            int W = Integer.parseInt(br.readLine());

            int[] dp = new int[N + 1];
            Queue<Integer> q = new LinkedList<>();

            for (int i = 1; i <= N; i++) {
                dp[i] = D[i];
                if (indegree[i] == 0) q.add(i);
            }

            while (!q.isEmpty()) {
                int now = q.poll();
                for (int next : graph[now]) {
                    dp[next] = Math.max(dp[next], dp[now] + D[next]);
                    indegree[next]--;
                    if (indegree[next] == 0) q.add(next);
                }
            }

            System.out.println(dp[W]);
        }
    }
}