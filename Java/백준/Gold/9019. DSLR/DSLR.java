import java.io.*;
import java.util.*;

public class Main {
    static class Node {
        int val;
        String cmd;
        Node(int val, String cmd) {
            this.val = val;
            this.cmd = cmd;
        }
    }

    static int D(int n) {
        return (2 * n) % 10000;
    }

    static int S(int n) {
        return n == 0 ? 9999 : n - 1;
    }

    static int L(int n) {
        return (n % 1000) * 10 + n / 1000;
    }

    static int R(int n) {
        return (n % 10) * 1000 + n / 10;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            boolean[] visited = new boolean[10000];
            Queue<Node> q = new LinkedList<>();
            q.add(new Node(A, ""));
            visited[A] = true;
            while (!q.isEmpty()) {
                Node cur = q.poll();
                if (cur.val == B) {
                    sb.append(cur.cmd).append("\n");
                    break;
                }
                int d = D(cur.val);
                if (!visited[d]) {
                    visited[d] = true;
                    q.add(new Node(d, cur.cmd + "D"));
                }
                int s = S(cur.val);
                if (!visited[s]) {
                    visited[s] = true;
                    q.add(new Node(s, cur.cmd + "S"));
                }
                int l = L(cur.val);
                if (!visited[l]) {
                    visited[l] = true;
                    q.add(new Node(l, cur.cmd + "L"));
                }
                int r = R(cur.val);
                if (!visited[r]) {
                    visited[r] = true;
                    q.add(new Node(r, cur.cmd + "R"));
                }
            }
        }
        System.out.print(sb.toString());
    }
}