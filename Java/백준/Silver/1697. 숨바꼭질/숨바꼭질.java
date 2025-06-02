import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static final int MAX = 100001;
    static boolean[] visited = new boolean[MAX];

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int K = Integer.parseInt(input[1]);

        System.out.print(bfs(N, K));
    }

    static int bfs(int start, int target) {
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{start, 0});
        visited[start] = true;

        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int position = current[0];
            int time = current[1];

            if (position == target) return time;

            int[] nextPositions = {position - 1, position + 1, position * 2};
            for (int next : nextPositions) {
                if (next >= 0 && next < MAX && !visited[next]) {
                    visited[next] = true;
                    queue.add(new int[]{next, time + 1});
                }
            }
        }

        return -1;
    }
}