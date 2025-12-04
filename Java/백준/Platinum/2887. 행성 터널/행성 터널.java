import java.io.*;
import java.util.*;

public class Main {
    static int[] parent;

    static class Planet {
        int index, x, y, z;

        Planet(int index, int x, int y, int z) {
            this.index = index;
            this.x = x;
            this.y = y;
            this.z = z;
        }
    }

    static class Edge implements Comparable<Edge> {
        int from, to, cost;

        Edge(int from, int to, int cost) {
            this.from = from;
            this.to = to;
            this.cost = cost;
        }

        public int compareTo(Edge o) {
            return this.cost - o.cost;
        }
    }

    static int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    static void union(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa != pb)
            parent[pb] = pa;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Planet[] planets = new Planet[n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int z = Integer.parseInt(st.nextToken());
            planets[i] = new Planet(i, x, y, z);
        }

        List<Edge> edges = new ArrayList<>();

        for (int d = 0; d < 3; d++) {
            int finalD = d;
            Arrays.sort(planets, (a, b) -> {
                if (finalD == 0) return a.x - b.x;
                else if (finalD == 1) return a.y - b.y;
                else return a.z - b.z;
            });
            for (int i = 0; i < n - 1; i++) {
                int cost = 0;
                if (finalD == 0)
                    cost = Math.abs(planets[i].x - planets[i + 1].x);
                else if (finalD == 1)
                    cost = Math.abs(planets[i].y - planets[i + 1].y);
                else
                    cost = Math.abs(planets[i].z - planets[i + 1].z);
                edges.add(new Edge(planets[i].index, planets[i + 1].index, cost));
            }
        }

        Collections.sort(edges);
        parent = new int[n];
        for (int i = 0; i < n; i++)
            parent[i] = i;

        int result = 0;
        for (Edge edge : edges) {
            if (find(edge.from) != find(edge.to)) {
                union(edge.from, edge.to);
                result += edge.cost;
            }
        }

        System.out.println(result);
    }
}