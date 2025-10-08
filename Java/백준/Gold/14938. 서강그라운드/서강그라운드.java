import java.io.*;
import java.util.*;

public class Main {
    static final int INF = 1000000;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken());
        int[] t = new int[n + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) t[i] = Integer.parseInt(st.nextToken());
        int[][] dist = new int[n + 1][n + 1];
        for (int i = 1; i <= n; i++) Arrays.fill(dist[i], INF);
        for (int i = 1; i <= n; i++) dist[i][i] = 0;
        for (int i = 0; i < r; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int l = Integer.parseInt(st.nextToken());
            dist[a][b] = Math.min(dist[a][b], l);
            dist[b][a] = Math.min(dist[b][a], l);
        }
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    if (dist[i][j] > dist[i][k] + dist[k][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int sum = 0;
            for (int j = 1; j <= n; j++)
                if (dist[i][j] <= m) sum += t[j];
            ans = Math.max(ans, sum);
        }
        System.out.println(ans);
    }
}