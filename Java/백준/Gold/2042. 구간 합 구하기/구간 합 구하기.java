import java.io.*;
import java.util.*;

public class Main {
    static long[] arr, tree;
    static int N;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        arr = new long[N + 1];
        tree = new long[N * 4];

        for (int i = 1; i <= N; i++) {
            arr[i] = Long.parseLong(br.readLine());
        }

        init(1, 1, N);

        int total = M + K;
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < total; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            long c = Long.parseLong(st.nextToken());

            if (a == 1) {
                long diff = c - arr[b];
                arr[b] = c;
                update(1, 1, N, b, diff);
            } else if (a == 2) {
                sb.append(sum(1, 1, N, b, (int) c)).append('\n');
            }
        }

        System.out.print(sb);
    }

    static long init(int node, int start, int end) {
        if (start == end) return tree[node] = arr[start];
        int mid = (start + end) / 2;
        return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
    }

    static void update(int node, int start, int end, int index, long diff) {
        if (index < start || index > end) return;
        tree[node] += diff;
        if (start != end) {
            int mid = (start + end) / 2;
            update(node * 2, start, mid, index, diff);
            update(node * 2 + 1, mid + 1, end, index, diff);
        }
    }

    static long sum(int node, int start, int end, int left, int right) {
        if (right < start || end < left) return 0;
        if (left <= start && end <= right) return tree[node];
        int mid = (start + end) / 2;
        return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
    }
}