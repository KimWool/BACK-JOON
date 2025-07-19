import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine()); //테스트 케이스 수

        for (int a = 0; a < n; a++) {
            String[] input = br.readLine().split(" ");
            String s = input[0];
            int i = Integer.parseInt(input[1]);
            int j = Integer.parseInt(input[2]);

            for (int b = 0; b < s.length(); b++) {
                if (b < i || b >= j) {
                    System.out.print(s.charAt(b));
                }
            }
            System.out.println();
        }
    }
}