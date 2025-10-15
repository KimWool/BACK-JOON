import java.io.*;
import java.util.*;

public class Main {
    static class Node implements Comparable<Node> {
        int v, cost;
        Node(int v, int cost) {
            this.v = v;
            this.cost = cost;
        }
        public int compareTo(Node o) {
            return this.cost - o.cost;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());
        List<List<Node>> graph = new ArrayList<>();
        for (int i = 0; i <= n; i++) graph.add(new ArrayList<>());
        for (int i = 0; i < m; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            graph.get(a).add(new Node(b, c));
        }
        StringTokenizer st = new StringTokenizer(br.readLine());
        int start = Integer.parseInt(st.nextToken());
        int end = Integer.parseInt(st.nextToken());

        int[] dist = new int[n + 1];
        int[] prev = new int[n + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[start] = 0;

        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.offer(new Node(start, 0));

        while (!pq.isEmpty()) {
            Node cur = pq.poll();
            if (cur.cost > dist[cur.v]) continue;
            for (Node next : graph.get(cur.v)) {
                if (dist[next.v] > cur.cost + next.cost) {
                    dist[next.v] = cur.cost + next.cost;
                    prev[next.v] = cur.v;
                    pq.offer(new Node(next.v, dist[next.v]));
                }
            }
        }

        System.out.println(dist[end]);

        List<Integer> path = new ArrayList<>();
        for (int v = end; v != 0; v = prev[v]) path.add(v);
        Collections.reverse(path);
        System.out.println(path.size());
        for (int v : path) System.out.print(v + " ");
    }
}