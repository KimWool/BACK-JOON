import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static long B;
    static int[][] A;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        B = Long.parseLong(st.nextToken());
        A = new int[N][N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                A[i][j] = Integer.parseInt(st.nextToken()) % 1000;
            }
        }
        int[][] result = pow(A, B);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                sb.append(result[i][j] % 1000).append(" ");
            }
            sb.append("\n");
        }
        System.out.print(sb);
    }

    static int[][] pow(int[][] matrix, long exp) {
        if (exp == 1) return matrix;
        int[][] half = pow(matrix, exp / 2);
        int[][] temp = multiply(half, half);
        if (exp % 2 == 0) return temp;
        else return multiply(temp, A);
    }

    static int[][] multiply(int[][] m1, int[][] m2) {
        int[][] res = new int[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                long sum = 0;
                for (int k = 0; k < N; k++) {
                    sum += (m1[i][k] * m2[k][j]);
                }
                res[i][j] = (int)(sum % 1000);
            }
        }
        return res;
    }
}