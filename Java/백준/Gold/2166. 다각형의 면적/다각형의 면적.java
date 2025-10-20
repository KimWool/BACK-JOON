import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        long[] x = new long[n];
        long[] y = new long[n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            x[i] = Long.parseLong(st.nextToken());
            y[i] = Long.parseLong(st.nextToken());
        }

        double area = 0;
        for (int i = 0; i < n; i++) {
            area += (x[i] * y[(i + 1) % n]) - (x[(i + 1) % n] * y[i]);
        }

        area = Math.abs(area) / 2.0;
        System.out.printf("%.1f\n", area);
    }
}