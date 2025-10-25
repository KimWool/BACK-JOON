import java.io.*;
import java.util.*;

public class Main {
    static class Edge implements Comparable<Edge> {
        int a, b, cost;
        public Edge(int a, int b, int cost) {
            this.a = a;
            this.b = b;
            this.cost = cost;
        }
        public int compareTo(Edge other) {
            return this.cost - other.cost;
        }
    }

    static int[] parent;

    static int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    static void union(int a, int b) {
        a = find(a);
        b = find(b);
        if (a < b) parent[b] = a;
        else parent[a] = b;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        List<Edge> edges = new ArrayList<>();
        parent = new int[n + 1];
        for (int i = 0; i <= n; i++) parent[i] = i;

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            edges.add(new Edge(a, b, cost));
        }

        Collections.sort(edges);

        int total = 0;
        int maxCost = 0;

        for (Edge edge : edges) {
            if (find(edge.a) != find(edge.b)) {
                union(edge.a, edge.b);
                total += edge.cost;
                maxCost = edge.cost;
            }
        }

        System.out.println(total - maxCost);
    }
}