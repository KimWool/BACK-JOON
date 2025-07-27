import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        for (int i = 0; i < T; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int D = Integer.parseInt(st.nextToken());

            int count = 0;

            for (int j = 0; j < N; j++) {
                st = new StringTokenizer(br.readLine());
                int vi = Integer.parseInt(st.nextToken());
                int fi = Integer.parseInt(st.nextToken());
                int ci = Integer.parseInt(st.nextToken());

                if ((long) vi * fi >= (long) D * ci) {
                    count++;
                }
            }

            System.out.println(count);
        }
    }
}