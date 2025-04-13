import java.io.*;

public class Main {
    public static void main(String[] args) {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N;
        try {
            N = Integer.parseInt(br.readLine()); //전체 사람의 수
            int[] x = new int[N]; //몸무게
            int[] y = new int[N]; //키
            int[] rank = new int[N];
            for (int i = 0; i < N; i++) {
                String[] input = br.readLine().split(" ");
                x[i] = Integer.parseInt(input[0]);
                y[i] = Integer.parseInt(input[1]);
                rank[i] = 1;
            }

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (x[i] < x[j] && y[i] < y[j]) {
                        rank[i]++;
                    }
                }
            }

            for (int i = 0; i < N; i++) {
                System.out.print(rank[i] + " ");
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}