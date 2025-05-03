import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int M = Integer.parseInt(br.readLine()); //수행해야 하는 연산의 수
        boolean[] set = new boolean[21];

        for (int i = 0; i < M; i++) {
            String[] input = br.readLine().split(" ");
            String cmd = input[0];

            switch (cmd) {
                case "add" -> {
                    int x = Integer.parseInt(input[1]);
                    set[x] = true;
                }
                case "remove" -> {
                    int x = Integer.parseInt(input[1]);
                    set[x] = false;
                }
                case "check" -> {
                    int x = Integer.parseInt(input[1]);
                    sb.append(set[x] ? "1\n" : "0\n");
                }
                case "toggle" -> {
                    int x = Integer.parseInt(input[1]);
                    set[x] = !set[x];
                }
                case "all" -> {
                    for (int j = 1; j <= 20; j++) {
                        set[j] = true;
                    }
                }
                case "empty" -> {
                    for (int j = 1; j <= 20; j++) {
                        set[j] = false;
                    }
                }
            }
        }

        System.out.print(sb);
    }
}