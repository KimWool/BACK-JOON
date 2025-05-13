import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine()); //테스트 케이스
        for (int i = 0; i < T; i++) {
            int n = Integer.parseInt(br.readLine()); //해빈이가 가진 의상의 수
            HashMap<String, Integer> cloths = new HashMap<>();
            for (int j = 0; j < n; j++) {
                String[] input = br.readLine().split(" ");
                String type = input[1];
                cloths.put(type, cloths.getOrDefault(type, 0) + 1);
            }
            int answer = 1;
            for (int count : cloths.values()) {
                answer *= (count + 1);
            }
            System.out.println(answer - 1);
        }
    }
}