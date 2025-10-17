import java.io.*;
import java.util.*;

public class Main {
    static List<Node>[] tree;
    static boolean[] visited;
    static int max = 0;
    static int node;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int V = Integer.parseInt(br.readLine());
        tree = new ArrayList[V + 1];

        for (int i = 1; i <= V; i++) {
            tree[i] = new ArrayList<>();
        }

        for (int i = 0; i < V; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());

            while (true) {
                int to = Integer.parseInt(st.nextToken());
                if (to == -1) break;
                int cost = Integer.parseInt(st.nextToken());
                tree[from].add(new Node(to, cost));
            }
        }

        visited = new boolean[V + 1];
        dfs(1, 0);

        visited = new boolean[V + 1];
        dfs(node, 0);

        System.out.println(max);
    }

    static void dfs(int x, int len) {
        if (len > max) {
            max = len;
            node = x;
        }

        visited[x] = true;

        for (Node n : tree[x]) {
            if (!visited[n.to]) {
                dfs(n.to, len + n.cost);
            }
        }
    }

    static class Node {
        int to, cost;

        Node(int to, int cost) {
            this.to = to;
            this.cost = cost;
        }
    }
}