import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static long A, B, C;

    static long pow(long a, long b) {
        if (b == 0) return 1;
        long half = pow(a, b / 2);
        long result = (half * half) % C;
        if (b % 2 == 1) result = (result * a) % C;
        return result;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        A = Long.parseLong(st.nextToken());
        B = Long.parseLong(st.nextToken());
        C = Long.parseLong(st.nextToken());
        System.out.println(pow(A % C, B));
    }
}