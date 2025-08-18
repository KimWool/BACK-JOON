import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int K = Integer.parseInt(br.readLine());

        for (int t = 0; t < K; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int P = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());

            boolean[] seats = new boolean[M + 1];
            int rejected = 0;

            for (int i = 0; i < P; i++) {
                int preferred = Integer.parseInt(br.readLine());
                if (!seats[preferred]) {
                    seats[preferred] = true;
                } else {
                    rejected++;
                }
            }

            System.out.println(rejected);
        }
    }
}