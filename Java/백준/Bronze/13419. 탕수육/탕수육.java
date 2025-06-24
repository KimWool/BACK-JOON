import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine()); //테스트 데이터

        for (int i = 0; i < T; i++) {
            String input = br.readLine();
            int length = input.length();

            StringBuilder first = new StringBuilder();
            boolean[] first_visited = new boolean[length];
            int first_index = 0;
            while (!first_visited[first_index]) {
                first_visited[first_index] = true;
                first.append(input.charAt(first_index));
                first_index = (first_index + 2) % length;
            }

            StringBuilder second = new StringBuilder();
            boolean[] second_visited = new boolean[length];
            int second_index = 1 % length;
            while (!second_visited[second_index]) {
                second_visited[second_index] = true;
                second.append(input.charAt(second_index));
                second_index = (second_index + 2) % length;
            }

            sb.append(first).append('\n').append(second).append('\n');
        }

        System.out.print(sb);
    }
}