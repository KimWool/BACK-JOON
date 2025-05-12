import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int node = Integer.parseInt(br.readLine()); //컴퓨터의 수
        int edge = Integer.parseInt(br.readLine()); //연결되어 있는 쌍의 수
        boolean[] visited = new boolean[node + 1];

        List<Integer>[] graph = new ArrayList[node + 1];

        for (int i = 1; i <= node; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int i = 0; i < edge; i++) {
            String[] input = br.readLine().split(" ");
            int a = Integer.parseInt(input[0]);
            int b = Integer.parseInt(input[1]);
            graph[a].add(b);
            graph[b].add(a);
        }

        System.out.print(dfs(1, visited, graph));
    }

    public static int dfs(int start, boolean[] visited, List<Integer>[] graph) {
        visited[start] = true;
        int count = 0;
        for (int next : graph[start]) {
            if (!visited[next]) {
                count += 1 + dfs(next, visited, graph);
            }
        }
        return count;
    }
}