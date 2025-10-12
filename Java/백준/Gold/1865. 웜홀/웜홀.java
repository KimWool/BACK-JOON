import java.io.*;
import java.util.*;

public class Main {
    static class Edge {
        int from, to, time;
        Edge(int from, int to, int time) {
            this.from = from;
            this.to = to;
            this.time = time;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int TC = Integer.parseInt(br.readLine());

        while (TC-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());
            int W = Integer.parseInt(st.nextToken());

            List<Edge> edges = new ArrayList<>();

            for (int i = 0; i < M; i++) {
                st = new StringTokenizer(br.readLine());
                int S = Integer.parseInt(st.nextToken());
                int E = Integer.parseInt(st.nextToken());
                int T = Integer.parseInt(st.nextToken());
                edges.add(new Edge(S, E, T));
                edges.add(new Edge(E, S, T));
            }

            for (int i = 0; i < W; i++) {
                st = new StringTokenizer(br.readLine());
                int S = Integer.parseInt(st.nextToken());
                int E = Integer.parseInt(st.nextToken());
                int T = Integer.parseInt(st.nextToken());
                edges.add(new Edge(S, E, -T));
            }

            boolean hasCycle = false;
            int[] dist = new int[N + 1];
            Arrays.fill(dist, 0);

            for (int i = 1; i <= N; i++) {
                for (Edge e : edges) {
                    if (dist[e.to] > dist[e.from] + e.time) {
                        dist[e.to] = dist[e.from] + e.time;
                        if (i == N) hasCycle = true;
                    }
                }
            }

            sb.append(hasCycle ? "YES\n" : "NO\n");
        }

        System.out.print(sb.toString());
    }
}