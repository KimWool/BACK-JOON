import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int N = s.nextInt(); //N개의 자연수 중에서
        int M = s.nextInt(); //M개를 고른 수열

        int[] array = new int[N + 1];;
        for (int i = 1; i <= N; i++) {
            array[i] = s.nextInt();
        }

        Arrays.sort(array);

        boolean[] visited = new boolean[N + 1];
        int[] arr = new int[M];
        backtrack(N, M, 0, array, arr, visited);

    }

    public static void backtrack(int n, int m, int depth, int[] array, int[] arr, boolean[] visited) {
        if (depth == m) {
            for (int i = 0; i < m; i++) {
                System.out.print(arr[i] + " ");
            }
            System.out.println();
            return;
        }
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                for (int j = i - 1; j >= 1; j--){
                    visited[j] = true;
                }
                arr[depth] = array[i];
                backtrack(n, m, depth + 1, array, arr, visited);
                for (int j = i - 1; j >= 1; j--){
                    visited[j] = false;
                }
            }
        }
    }
}