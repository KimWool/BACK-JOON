import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;

public class Main {
    public static void main(String[] args) {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N; //명령의 수

        try {
            LinkedList<Integer> queue = new LinkedList<>();
            N = Integer.parseInt(br.readLine());
            for (int i = 0; i < N; i++) {
                String[] input = br.readLine().split(" ");
                switch (input[0]) {
                    case "push":
                        queue.add(Integer.parseInt(input[1]));
                        break;
                    case "pop":
                        if (queue.isEmpty()) {
                            System.out.println(-1);
                        } else {
                            System.out.println(queue.poll());
                        }
                        break;
                    case "size":
                        System.out.println(queue.size());
                        break;
                    case "empty":
                        if (!queue.isEmpty()) {
                            System.out.println(0);
                        } else {
                            System.out.println(1);
                        }
                        break;
                    case "front":
                        if (queue.isEmpty()) {
                            System.out.println(-1);
                        } else {
                            System.out.println(queue.peek());
                        }
                        break;
                    case "back":
                        if (queue.isEmpty()) {
                            System.out.println(-1);
                        } else {
                            System.out.println(queue.getLast());
                        }
                        break;
                    default:
                }
            }

        } catch (IOException e) {
            throw new RuntimeException(e);
        }

    }
}