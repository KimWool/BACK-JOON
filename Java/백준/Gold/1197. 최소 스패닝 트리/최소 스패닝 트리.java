import java.io.*;
import java.util.*;

public class Main {

    static int[] parent;

    static int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    static void union(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA != rootB) {
            parent[rootB] = rootA;
        }
    }

    static class Edge implements Comparable<Edge> {
        int A, B, C;

        Edge(int A, int B, int C) {
            this.A = A;
            this.B = B;
            this.C = C;
        }

        public int compareTo(Edge o) {
            return this.C - o.C;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int V = Integer.parseInt(st.nextToken());
        int E = Integer.parseInt(st.nextToken());

        parent = new int[V + 1];
        for (int i = 1; i <= V; i++) {
            parent[i] = i;
        }

        PriorityQueue<Edge> pq = new PriorityQueue<>();
        for (int i = 0; i < E; i++) {
            st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            int C = Integer.parseInt(st.nextToken());
            pq.offer(new Edge(A, B, C));
        }

        int result = 0;
        while (!pq.isEmpty()) {
            Edge edge = pq.poll();
            if (find(edge.A) != find(edge.B)) {
                union(edge.A, edge.B);
                result += edge.C;
            }
        }

        System.out.println(result);
    }
}