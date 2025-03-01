import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int N = s.nextInt(); //1부터 N까지의 자연수 중에서
        int M = s.nextInt(); //중복 없이 M개를 고른 수열을 구하시오

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
                visited[i] = true;
                arr[depth] = i;
                backtrack(n, m, depth + 1, arr, visited);
                visited[i] = false;
            }
        }
    }
}