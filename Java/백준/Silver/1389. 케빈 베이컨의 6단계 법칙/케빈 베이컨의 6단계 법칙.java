import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static class Graph {
        private final int V; //정점 개수
        private final List<List<Integer>> list;

        public Graph(int vertices) {
            V = vertices;
            list = new ArrayList<>();
            for (int i = 0; i < V; i++) {
                list.add(new ArrayList<>());
            }
        }

        public void addEdge(int u, int v) {
            list.get(u).add(v);
            list.get(v).add(u);
        }

        public List<Integer> getNeighbors(int u) {
            return list.get(u);
        }

        public int getVertexCount() {
            return V;
        }
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]); //유저의 수
        int M = Integer.parseInt(input[1]); //친구 관계의 수

        Graph graph = new Graph(N);
        for (int i = 0; i < M; i++) {
            String[] vertices = br.readLine().split(" ");
            int u = Integer.parseInt(vertices[0]) - 1;
            int v = Integer.parseInt(vertices[1]) - 1;
            graph.addEdge(u, v);
        }

        int minBacon = Integer.MAX_VALUE;
        int person = -1;

        for (int i = 0; i < N; i++) {
            int baconSum = bfs(graph, i);
            if (baconSum < minBacon) {
                minBacon = baconSum;
                person = i;
            }
        }

        System.out.print(person + 1);
    }

    public static int bfs(Graph graph, int start) {
        int[] dist = new int[graph.getVertexCount()];
        Arrays.fill(dist, -1);
        Queue<Integer> queue = new LinkedList<>();

        dist[start] = 0;
        queue.add(start);

        while (!queue.isEmpty()) {
            int curr = queue.poll();
            for (int neighbor : graph.getNeighbors(curr)) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[curr] + 1;
                    queue.add(neighbor);
                }
            }
        }

        int sum = 0;
        for (int d : dist) sum += d;
        return sum;
    }
}