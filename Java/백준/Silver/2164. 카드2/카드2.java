import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;

public class Main {
    public static void main(String[] args) {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        try {
            int N = Integer.parseInt(br.readLine());
            Deque<Integer> stack = new ArrayDeque<>();
            for (int i = 1; i <= N; i++) {
                stack.addLast(i);
            }
            while (stack.size() != 1) {
                stack.removeFirst(); //제일 위에 있는 카드를 바닥에 버린다.
                stack.addLast(stack.removeFirst()); //제일 위에 있는 카드를 제일 아래에 있는 카드 밑으로 옮긴다.
            }
            System.out.print(stack.peekFirst());
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}