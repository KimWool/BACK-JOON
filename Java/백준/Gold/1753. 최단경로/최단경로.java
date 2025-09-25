import java.io.*;
import java.util.*;

public class Main {
    static class Node implements Comparable<Node> {
        int v, w;
        Node(int v, int w) {
            this.v = v;
            this.w = w;
        }
        public int compareTo(Node o) {
            return this.w - o.w;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int V = Integer.parseInt(st.nextToken());
        int E = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(br.readLine());

        List<Node>[] graph = new ArrayList[V + 1];
        for (int i = 1; i <= V; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int i = 0; i < E; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            graph[u].add(new Node(v, w));
        }

        int[] dist = new int[V + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[K] = 0;

        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.add(new Node(K, 0));

        while (!pq.isEmpty()) {
            Node cur = pq.poll();
            if (dist[cur.v] < cur.w) continue;
            for (Node next : graph[cur.v]) {
                if (dist[next.v] > cur.w + next.w) {
                    dist[next.v] = cur.w + next.w;
                    pq.add(new Node(next.v, dist[next.v]));
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= V; i++) {
            if (dist[i] == Integer.MAX_VALUE) sb.append("INF\n");
            else sb.append(dist[i]).append("\n");
        }
        System.out.print(sb);
    }
}