import java.io.*;
import java.util.*;

public class Main {
    static class Node implements Comparable<Node> {
        int end, cost;
        Node(int end, int cost) {
            this.end = end;
            this.cost = cost;
        }
        public int compareTo(Node o) {
            return this.cost - o.cost;
        }
    }

    static int N, M, X;
    static List<Node>[] graph, reverseGraph;
    static final int INF = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        X = Integer.parseInt(st.nextToken());

        graph = new ArrayList[N + 1];
        reverseGraph = new ArrayList[N + 1];
        for (int i = 1; i <= N; i++) {
            graph[i] = new ArrayList<>();
            reverseGraph[i] = new ArrayList<>();
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            graph[start].add(new Node(end, cost));
            reverseGraph[end].add(new Node(start, cost));
        }

        int[] go = dijkstra(graph, X);
        int[] back = dijkstra(reverseGraph, X);

        int maxTime = 0;
        for (int i = 1; i <= N; i++) {
            if (go[i] == INF || back[i] == INF) continue;
            maxTime = Math.max(maxTime, go[i] + back[i]);
        }

        System.out.println(maxTime);
    }

    static int[] dijkstra(List<Node>[] g, int start) {
        PriorityQueue<Node> pq = new PriorityQueue<>();
        int[] dist = new int[N + 1];
        Arrays.fill(dist, INF);
        dist[start] = 0;
        pq.offer(new Node(start, 0));

        while (!pq.isEmpty()) {
            Node cur = pq.poll();
            if (cur.cost > dist[cur.end]) continue;
            for (Node next : g[cur.end]) {
                if (dist[next.end] > dist[cur.end] + next.cost) {
                    dist[next.end] = dist[cur.end] + next.cost;
                    pq.offer(new Node(next.end, dist[next.end]));
                }
            }
        }
        return dist;
    }
}