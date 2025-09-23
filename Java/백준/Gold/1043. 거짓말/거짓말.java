import java.io.*;
import java.util.*;

public class Main {
    static int[] parent;

    static int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    static void union(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) parent[b] = a;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        parent = new int[N + 1];
        for (int i = 1; i <= N; i++) parent[i] = i;

        st = new StringTokenizer(br.readLine());
        int cnt = Integer.parseInt(st.nextToken());
        int[] truth = new int[cnt];
        for (int i = 0; i < cnt; i++) truth[i] = Integer.parseInt(st.nextToken());

        List<int[]> party = new ArrayList<>();
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int k = Integer.parseInt(st.nextToken());
            int[] arr = new int[k];
            for (int j = 0; j < k; j++) arr[j] = Integer.parseInt(st.nextToken());
            party.add(arr);
            for (int j = 0; j < k - 1; j++) union(arr[j], arr[j + 1]);
        }

        boolean[] know = new boolean[N + 1];
        for (int t : truth) know[find(t)] = true;

        int ans = 0;
        for (int[] p : party) {
            boolean flag = true;
            for (int person : p) {
                if (know[find(person)]) {
                    flag = false;
                    break;
                }
            }
            if (flag) ans++;
        }

        System.out.println(ans);
    }
}