import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] condition = br.readLine().split(" ");
        int T = Integer.parseInt(condition[0]); //예약할 수 있는 교시의 개수
        int X = Integer.parseInt(condition[1]); //예약한 교시

        int temp = 0;
        int N = Integer.parseInt(br.readLine()); //조원의 수

        for (int i = 0; i < N; i++) {
            int K = Integer.parseInt(br.readLine()); //예약할 수 있는 교시의 개수
            String[] time = br.readLine().split(" ");
            for (int j = 0; j < K; j++) {
                if (Integer.parseInt(time[j]) == X) {
                    temp++;
                }
            }
        }

        if (temp == N) {
            System.out.print("YES");
        } else {
            System.out.print("NO");
        }
    }
}