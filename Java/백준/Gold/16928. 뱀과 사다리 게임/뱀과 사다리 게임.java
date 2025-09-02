import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]); //사다리의 수
        int M = Integer.parseInt(input[1]); //뱀의 수

        HashMap<Integer, Integer> ladder = new HashMap<>();
        HashMap<Integer, Integer> snake = new HashMap<>();

        for (int i = 0; i < N; i++) {
            String[] line = br.readLine().split(" ");
            int x = Integer.parseInt(line[0]);
            int y = Integer.parseInt(line[1]);
            ladder.put(x, y);
        }

        for (int i = 0; i < M; i++) {
            String[] line = br.readLine().split(" ");
            int u = Integer.parseInt(line[0]);
            int v = Integer.parseInt(line[1]);
            snake.put(u, v);
        }

        boolean[] visited = new boolean[101];
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{1, 0});
        visited[1] = true;

        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int position = current[0];
            int moves = current[1];

            if (position == 100) {
                System.out.print(moves);
                return;
            }

            for (int i = 1; i <= 6; i++) {
                int next = position + i;
                if (next > 100) continue;

                if (ladder.containsKey(next)) {
                    next = ladder.get(next);
                } else if (snake.containsKey(next)) {
                    next = snake.get(next);
                }

                if (!visited[next]) {
                    visited[next] = true;
                    queue.offer(new int[]{next, moves + 1});
                }
            }
        }
    }
}