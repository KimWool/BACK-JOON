import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {
    static int N;
    static List<List<Integer>> graph = new ArrayList<>();
    static int[][] result;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine()); //정점의 개수
        result = new int[N][N];

        for (int i = 0; i < N; i++) { //리스트 초기화
            graph.add(new ArrayList<>());
        }

        for (int i = 0; i < N; i++) {
            String[] input = br.readLine().split(" ");
            for (int j = 0; j < N; j++) {
                if (input[j].equals("1")) { //간선 추가
                    graph.get(i).add(j);
                }
            }
        }

        for (int i = 0; i < N; i++) {
            visited = new boolean[N];
            dfs(i, i);
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                System.out.print(result[i][j] + " ");
            }
            System.out.println();
        }
    }

    static void dfs(int start, int curr) {
        for (int next : graph.get(curr)) {
            if (!visited[next]) {
                visited[next] = true;
                result[start][next] = 1;
                dfs(start, next);
            }
        }
    }
}