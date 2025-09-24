import java.io.*;
import java.util.*;

public class Main {
    static class Node implements Comparable<Node> {
        int vertex, cost;
        Node(int vertex, int cost) {
            this.vertex = vertex;
            this.cost = cost;
        }
        public int compareTo(Node o) {
            return this.cost - o.cost;
        }
    }

    static int N, E;
    static List<Node>[] graph;
    static final int INF = 200000000;

    static int dijkstra(int start, int end) {
        PriorityQueue<Node> pq = new PriorityQueue<>();
        int[] dist = new int[N + 1];
        Arrays.fill(dist, INF);
        dist[start] = 0;
        pq.add(new Node(start, 0));

        while (!pq.isEmpty()) {
            Node now = pq.poll();
            if (dist[now.vertex] < now.cost) continue;
            for (Node next : graph[now.vertex]) {
                if (dist[next.vertex] > dist[now.vertex] + next.cost) {
                    dist[next.vertex] = dist[now.vertex] + next.cost;
                    pq.add(new Node(next.vertex, dist[next.vertex]));
                }
            }
        }
        return dist[end];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());

        graph = new ArrayList[N + 1];
        for (int i = 1; i <= N; i++) graph[i] = new ArrayList<>();

        for (int i = 0; i < E; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            graph[a].add(new Node(b, c));
            graph[b].add(new Node(a, c));
        }

        st = new StringTokenizer(br.readLine());
        int v1 = Integer.parseInt(st.nextToken());
        int v2 = Integer.parseInt(st.nextToken());

        long route1 = 0;
        route1 += dijkstra(1, v1);
        route1 += dijkstra(v1, v2);
        route1 += dijkstra(v2, N);

        long route2 = 0;
        route2 += dijkstra(1, v2);
        route2 += dijkstra(v2, v1);
        route2 += dijkstra(v1, N);

        long answer = Math.min(route1, route2);
        if (answer >= INF) System.out.println(-1);
        else System.out.println(answer);
    }
}