import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N, M;

        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]); //듣도 못한 사람의 수
        M = Integer.parseInt(input[1]); //보도 못한 사람의 수

        Set<String> notListen = new HashSet<>();
        for (int i = 0; i < N; i++) {
            notListen.add(br.readLine());
        }

        List<String> result = new ArrayList<>();
        for (int i = 0; i < M; i++) {
            String name = br.readLine();
            if (notListen.contains(name)) {
                result.add(name);
            }
        }

        Collections.sort(result);

        System.out.println(result.size());
        for (String r : result) {
            System.out.println(r);
        }
    }
}