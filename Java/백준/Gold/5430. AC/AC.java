import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine()); //테스트 케이스 개수

        for (int i = 0; i < T; i++) {
            String command = br.readLine();
            int n = Integer.parseInt(br.readLine()); //배열 크기

            String input = br.readLine();
            input = input.replaceAll("[\\[\\]]", "");
            String[] tokens = input.isEmpty() ? new String[0] : input.split(",");

            Deque<Integer> deque = new ArrayDeque<>();
            for (String token : tokens) {
                deque.addLast(Integer.parseInt(token));
            }

            boolean isReversed = false;
            boolean isError = false;

            for (char c : command.toCharArray()) {
                if (c == 'R') {
                    isReversed = !isReversed;
                } else if (c == 'D') {
                    if (deque.isEmpty()) {
                        System.out.println("error");
                        isError = true;
                        break;
                    }

                    if (isReversed) {
                        deque.removeLast();
                    } else {
                        deque.removeFirst();
                    }
                }
            }

            if (!isError) {
                StringBuilder sb = new StringBuilder();
                sb.append("[");

                while (!deque.isEmpty()) {
                    sb.append(isReversed ? deque.removeLast() : deque.removeFirst());
                    if (!deque.isEmpty()) {
                        sb.append(",");
                    }
                }

                sb.append("]");
                System.out.println(sb);
            }
        }
    }
}