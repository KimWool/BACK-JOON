import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int sum = 0;

        int N = Integer.parseInt(br.readLine()); //맞추어야 하는 노브 각도의 개수
        int A = Integer.parseInt(br.readLine()); //노브의 초기 각도

        int[] Angles = new int[N]; //맞추어야 하는 노브 각도
        for (int i = 0; i < N; i++) {
            Angles[i] = Integer.parseInt(br.readLine());
            int case1 = Math.abs(Angles[i] - A);
            int case2 = 360 - case1;
            sum += Math.min(case1, case2);
            A = Angles[i];
        }

        System.out.print(sum);
    }
}