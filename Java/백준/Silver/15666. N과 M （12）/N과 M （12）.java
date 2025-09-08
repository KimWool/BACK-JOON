import java.io.*;
import java.util.*;

public class Main {
    static int N, M;
    static int[] unique;
    static int U;
    static int[] seq;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        int[] input = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) input[i] = Integer.parseInt(st.nextToken());
        Arrays.sort(input);

        unique = new int[N];
        U = 0;
        int prev = Integer.MIN_VALUE;
        for (int x : input) {
            if (x != prev) {
                unique[U++] = x;
                prev = x;
            }
        }

        seq = new int[M];
        dfs(0, 0);

        System.out.print(sb);
    }

    static void dfs(int depth, int start) {
        if (depth == M) {
            for (int i = 0; i < M; i++) {
                if (i > 0) sb.append(' ');
                sb.append(seq[i]);
            }
            sb.append('\n');
            return;
        }
        for (int i = start; i < U; i++) {
            seq[depth] = unique[i];
            dfs(depth + 1, i);
        }
    }
}