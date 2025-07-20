import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine()); //테스트 케이스 수
        for (int i = 0; i < T; i++) {
            String[] input = br.readLine().split(" ");
            int G = Integer.parseInt(input[0]); //그룹
            int C = Integer.parseInt(input[1]); //현재 사탕 수
            int E = Integer.parseInt(input[2]); //진화에 필요한 사탕 수

            int kilometer = switch (G) {
                case 1 -> 1;
                case 2 -> 3;
                case 3 -> 5;
                default -> 0;
            };

            if (C >= E) {
                System.out.println(0);
            } else {
                int diff = E - C;
                System.out.println(diff * kilometer);
            }
        }
    }
}