import java.io.*;
import java.util.*;

public class Main {
    static int[] parent;
    static int[] candyCount;
    static int[] groupSize;
    static int[] groupCandy;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        parent = new int[N + 1];
        candyCount = new int[N + 1];

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            candyCount[i] = Integer.parseInt(st.nextToken());
            parent[i] = i;
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            union(a, b);
        }

        groupSize = new int[N + 1];
        groupCandy = new int[N + 1];

        for (int i = 1; i <= N; i++) {
            int root = find(i);
            groupSize[root]++;
            groupCandy[root] += candyCount[i];
        }

        int[] dp = new int[K];

        for (int i = 1; i <= N; i++) {
            if (i != find(i)) continue;

            int size = groupSize[i];
            int candy = groupCandy[i];

            for (int j = K - 1; j >= size; j--) {
                dp[j] = Math.max(dp[j], dp[j - size] + candy);
            }
        }

        System.out.println(dp[K - 1]);
    }

    static int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    static void union(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa != pb) parent[pb] = pa;
    }
}