import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        Match[] matches = new Match[7];
        matches[0] = new Match(9.23076, 26.7, 1.835, true);
        matches[1] = new Match(1.84523, 75, 1.348, false);
        matches[2] = new Match(56.0211, 1.5, 1.05, false);
        matches[3] = new Match(4.99087, 42.5, 1.81, true);
        matches[4] = new Match(0.188807, 210, 1.41, false);
        matches[5] = new Match(15.9803, 3.8, 1.04, false);
        matches[6] = new Match(0.11193, 254, 1.88, true);

        int T = Integer.parseInt(br.readLine()); //테스트 케이스의 개수

        for (int i = 0; i < T; i++) {
            int result = 0;
            String[] input = br.readLine().split(" ");
            for (int j = 0; j < 7; j++) {
                int score;
                int P = Integer.parseInt(input[j]);
                if (matches[j].flag) { //트랙
                    score = (int) Math.floor(matches[j].A * Math.pow(matches[j].B - P, matches[j].C));
                } else {
                    score = (int) Math.floor(matches[j].A * Math.pow(P - matches[j].B, matches[j].C));
                }
                result += score;
            }
            System.out.println(result);
        }
    }

    public static class Match {
        double A, B, C;
        boolean flag; //True면 트랙, False면 필드

        public Match(double A, double B, double C, boolean flag) {
            this.A = A;
            this.B = B;
            this.C = C;
            this.flag = flag;
        }
    }
}