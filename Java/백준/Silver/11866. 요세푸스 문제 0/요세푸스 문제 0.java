import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    public static void main(String[] args) {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        try {
            String[] input = br.readLine().split(" ");
            int N = Integer.parseInt(input[0]);
            int K = Integer.parseInt(input[1]);

            Queue<Integer> queue = new LinkedList<>();
            for (int i = 1; i <= N; i++) {
                queue.offer(i);
            }

            int index = 1;
            sb.append("<");

            while (!queue.isEmpty()) {
                if (index % K == 0) {
                    sb.append(queue.poll());
                    if (!queue.isEmpty()) {
                        sb.append(", ");
                    }
                } else {
                    queue.offer(queue.poll());
                }
                index++;
            }

            sb.append(">");
            System.out.print(sb);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

    }
}