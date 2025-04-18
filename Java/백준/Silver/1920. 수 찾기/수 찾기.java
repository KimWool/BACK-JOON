import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        try {
            int N = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());
            HashSet<Integer> set = new HashSet<>(N);
            for (int i = 0; i < N; i++) {
                set.add(Integer.parseInt(st.nextToken())); //이 수들 안에 존재하는가?
            }
            int M = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < M; i++) {
                int exist = Integer.parseInt(st.nextToken());
                sb.append(set.contains(exist) ? 1 : 0).append("\n");
            }
            System.out.print(sb);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

    }
}