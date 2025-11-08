import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        List<Integer>[] graph = new ArrayList[n + 1];
        int[] indegree = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int count = Integer.parseInt(st.nextToken());
            int prev = Integer.parseInt(st.nextToken());
            for (int j = 1; j < count; j++) {
                int curr = Integer.parseInt(st.nextToken());
                graph[prev].add(curr);
                indegree[curr]++;
                prev = curr;
            }
        }

        Queue<Integer> q = new LinkedList<>();
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                q.offer(i);
            }
        }

        StringBuilder sb = new StringBuilder();
        int processed = 0;

        while (!q.isEmpty()) {
            int now = q.poll();
            sb.append(now).append('\n');
            processed++;

            for (int next : graph[now]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.offer(next);
                }
            }
        }

        if (processed != n) {
            System.out.println(0);
        } else {
            System.out.print(sb);
        }
    }
}