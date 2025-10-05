import java.io.*;
import java.util.*;

public class Main {
    static int N, K;
    static int[] dist = new int[100001];
    static int minTime = Integer.MAX_VALUE;
    static int count = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        if (N >= K) {
            System.out.println((N - K) + "\n1");
            return;
        }

        Arrays.fill(dist, -1);
        bfs();
        System.out.println(minTime);
        System.out.println(count);
    }

    static void bfs() {
        Queue<Integer> q = new LinkedList<>();
        q.add(N);
        dist[N] = 0;

        while (!q.isEmpty()) {
            int cur = q.poll();

            if (cur == K) {
                if (dist[cur] < minTime) {
                    minTime = dist[cur];
                    count = 1;
                } else if (dist[cur] == minTime) {
                    count++;
                }
                continue;
            }

            for (int next : new int[]{cur - 1, cur + 1, cur * 2}) {
                if (next < 0 || next > 100000) continue;

                if (dist[next] == -1 || dist[next] == dist[cur] + 1) {
                    dist[next] = dist[cur] + 1;
                    q.add(next);
                }
            }
        }
    }
}