import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int N = s.nextInt();
        int M = s.nextInt();

        boolean[] visited = new boolean[N + 1];
        int[] arr = new int[M];
        backtrack(N, M, 0, arr, visited);

    }

    public static void backtrack(int n, int m, int depth, int[] arr, boolean[] visited) {
        if (depth == m) {
            for (int i = 0; i < m; i++) {
                System.out.print(arr[i] + " ");
            }
            System.out.println();
            return;
        }
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                for (int j = i - 1; j >= 1; j--) {
                    visited[j] = true;
                }
                arr[depth] = i;
                backtrack(n, m, depth + 1, arr, visited);
                for (int j = i - 1; j >= 1; j--) {
                    visited[j] = false;
                }
            }
        }
    }
}