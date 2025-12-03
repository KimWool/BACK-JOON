import java.io.*;
import java.util.*;

public class Main {
    static class Wire implements Comparable<Wire> {
        int a, b;
        Wire(int a, int b) {
            this.a = a;
            this.b = b;
        }
        public int compareTo(Wire o) {
            return this.a - o.a;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Wire[] wires = new Wire[n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            wires[i] = new Wire(a, b);
        }

        Arrays.sort(wires);

        int[] dp = new int[n];
        int[] lis = new int[n];
        int[] prevIndex = new int[n];
        Arrays.fill(prevIndex, -1);

        int len = 0;
        int[] indices = new int[n];

        for (int i = 0; i < n; i++) {
            int pos = Arrays.binarySearch(dp, 0, len, wires[i].b);
            if (pos < 0) pos = -pos - 1;

            dp[pos] = wires[i].b;
            indices[pos] = i;
            if (pos > 0) prevIndex[i] = indices[pos - 1];

            if (pos == len) len++;
            lis[i] = pos;
        }

        boolean[] isInLIS = new boolean[n];
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (lis[i] == len - 1) {
                idx = i;
                break;
            }
        }

        while (idx != -1) {
            isInLIS[idx] = true;
            idx = prevIndex[idx];
        }

        StringBuilder sb = new StringBuilder();
        sb.append(n - len).append("\n");

        List<Integer> remove = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (!isInLIS[i]) {
                remove.add(wires[i].a);
            }
        }

        Collections.sort(remove);
        for (int a : remove) {
            sb.append(a).append("\n");
        }

        System.out.print(sb.toString());
    }
}