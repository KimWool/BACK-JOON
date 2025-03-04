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
        int[] arr = new int[M];
        StringBuilder sb = new StringBuilder();
        backtrack(N, M, 0, array, arr, sb);
        System.out.print(sb.toString());

    }

    public static void backtrack(int n, int m, int depth, int[] array, int[] arr, StringBuilder sb) {
        if (depth == m) {
            for (int i = 0; i < m; i++) {
                sb.append(arr[i]).append(" ");
            }
            sb.append("\n");
            return;
        }
        for (int i = 1; i <= n; i++) {
            arr[depth] = array[i];
            backtrack(n, m, depth + 1, array, arr, sb);
        }
    }
}