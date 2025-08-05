import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    static int[] triangle = new int[45];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        // 삼각수 배열 초기화
        for (int i = 1; i < 45; i++) {
            triangle[i] = i * (i + 1) / 2;
        }

        StringBuilder sb = new StringBuilder();

        while (T-- > 0) {
            int K = Integer.parseInt(br.readLine());
            sb.append(eureka(K) ? "1\n" : "0\n");
        }

        System.out.print(sb);
    }

    static boolean eureka(int K) {
        for (int i = 1; i < 45; i++) {
            for (int j = 1; j < 45; j++) {
                for (int k = 1; k < 45; k++) {
                    if (triangle[i] + triangle[j] + triangle[k] == K) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
}