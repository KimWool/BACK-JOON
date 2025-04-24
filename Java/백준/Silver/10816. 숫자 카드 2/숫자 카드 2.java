import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        try {
            int N = Integer.parseInt(br.readLine()); //상근이가 가지고 있는 숫자 카드의 개수
            String[] havingStr = br.readLine().split(" ");

            HashMap<Integer, Integer> cardCount = new HashMap<>();
            for (int i = 0; i < N; i++) {
                int num = Integer.parseInt(havingStr[i]);
                cardCount.put(num, cardCount.getOrDefault(num, 0) + 1);
            }

            int M = Integer.parseInt(br.readLine()); //구해야 할 숫자 카드 개수
            String[] howManyStr = br.readLine().split(" ");

            for (int i = 0; i < M; i++) {
                int num = Integer.parseInt(howManyStr[i]);
                sb.append(cardCount.getOrDefault(num, 0)).append(" ");
            }

            System.out.println(sb.toString().trim());
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}