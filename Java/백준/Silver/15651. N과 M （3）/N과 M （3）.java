import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int N = s.nextInt();
        int M = s.nextInt();

        int[] arr = new int[M];
        StringBuilder sb = new StringBuilder();
        backtrack(N, M, 0, arr, sb);
        System.out.println(sb.toString());

    }

    public static void backtrack(int n, int m, int depth, int[] arr, StringBuilder sb) {
        if (depth == m) {
            for (int i = 0; i < m; i++) {
                sb.append(arr[i]).append(" ");
            }
            sb.append("\n");
            return;
        }
        for (int i = 1; i <= n; i++) {
            arr[depth] = i;
            backtrack(n, m, depth + 1, arr, sb);
        }
    }
}