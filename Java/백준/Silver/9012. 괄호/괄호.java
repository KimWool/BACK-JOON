import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T; //T개의 테스트 데이터
        String line;

        try {
            T = Integer.parseInt(br.readLine());
            for (int i = 0; i < T; i++) {
                line = br.readLine();
                Stack<Character> stack = new Stack<>();
                boolean isBalanced = true;

                for (int j = 0; j < line.length(); j++) {
                    char ch = line.charAt(j);

                    if (ch == '(') {
                        stack.push(ch);
                    } else if (ch == ')') {
                        if (stack.isEmpty() || stack.peek() != '(') {
                            isBalanced = false;
                            break;
                        } else {
                            stack.pop();
                        }
                    }
                }

                if (!stack.isEmpty()) isBalanced = false;

                System.out.println(isBalanced ? "YES" : "NO");
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}