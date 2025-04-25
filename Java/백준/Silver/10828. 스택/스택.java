import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N; //명령의 수

        try {
            Stack<Integer> stack = new Stack<>();
            N = Integer.parseInt(br.readLine());
            for (int i = 0; i < N; i++) {
                String[] input = br.readLine().split(" ");
                switch (input[0]) {
                    case "push":
                        stack.push(Integer.parseInt(input[1]));
                        break;
                    case "pop":
                        if (stack.isEmpty()) {
                            System.out.println(-1);
                        } else {
                            System.out.println(stack.pop());
                        }
                        break;
                    case "size":
                        System.out.println(stack.size());
                        break;
                    case "empty":
                        if (!stack.isEmpty()) {
                            System.out.println(0);
                        } else {
                            System.out.println(1);
                        }
                        break;
                    case "top":
                        if (stack.isEmpty()) {
                            System.out.println(-1);
                        } else {
                            System.out.println(stack.peek());
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