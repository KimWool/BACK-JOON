import java.io.*;
import java.util.*;

public class Main {
    static int N, K;
    static int MAX = 100000;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        int[] dist = new int[MAX + 1];
        Arrays.fill(dist, -1);

        Deque<Integer> dq = new ArrayDeque<>();
        dq.add(N);
        dist[N] = 0;

        while (!dq.isEmpty()) {
            int x = dq.poll();
            if (x == K) {
                System.out.println(dist[x]);
                return;
            }
            int nx = x * 2;
            if (nx <= MAX && dist[nx] == -1) {
                dist[nx] = dist[x];
                dq.addFirst(nx);
            }
            nx = x - 1;
            if (nx >= 0 && dist[nx] == -1) {
                dist[nx] = dist[x] + 1;
                dq.addLast(nx);
            }
            nx = x + 1;
            if (nx <= MAX && dist[nx] == -1) {
                dist[nx] = dist[x] + 1;
                dq.addLast(nx);
            }
        }
    }
}