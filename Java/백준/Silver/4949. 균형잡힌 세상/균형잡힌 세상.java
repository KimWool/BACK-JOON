import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String line;

        try {
            while (true) {
                line = br.readLine();
                if (line.equals(".")) { break; }
                Stack<Character> stack = new Stack<>();
                boolean isBalanced = true;

                for (int i = 0; i < line.length(); i++) {
                    char ch = line.charAt(i);

                    if (ch == '(' || ch == '[') {
                        stack.push(ch);
                    } else if (ch == ')') {
                        if (stack.isEmpty() || stack.peek() != '(') {
                            isBalanced = false;
                            break;
                        } else {
                            stack.pop();
                        }
                    } else if (ch == ']') {
                        if (stack.isEmpty() || stack.peek() != '[') {
                            isBalanced = false;
                            break;
                        } else {
                            stack.pop();
                        }
                    }
                }

                if (!stack.isEmpty()) isBalanced = false;

                System.out.println(isBalanced ? "yes" : "no");
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}