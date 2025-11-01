import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] x = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        int max = 0;
        for (int i = 0; i < N; i++) {
            x[i] = Integer.parseInt(st.nextToken());
            if (x[i] > max) max = x[i];
        }

        int[] count = new int[1000001];
        for (int i = 0; i < N; i++) {
            count[x[i]] = 1;
        }

        int[] score = new int[1000001];
        for (int i = 0; i < N; i++) {
            int a = x[i];
            for (int j = a * 2; j <= 1000000; j += a) {
                if (count[j] == 1) {
                    score[a]++;
                    score[j]--;
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < N; i++) {
            sb.append(score[x[i]]).append(" ");
        }
        System.out.println(sb);
    }
}