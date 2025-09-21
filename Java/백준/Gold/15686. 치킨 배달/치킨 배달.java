import java.io.*;
import java.util.*;

public class Main {
    static int N, M;
    static List<int[]> house = new ArrayList<>();
    static List<int[]> chicken = new ArrayList<>();
    static int answer = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                int val = Integer.parseInt(st.nextToken());
                if (val == 1) house.add(new int[]{i, j});
                else if (val == 2) chicken.add(new int[]{i, j});
            }
        }

        comb(0, 0, new ArrayList<>());
        System.out.println(answer);
    }

    static void comb(int start, int depth, List<int[]> selected) {
        if (depth == M) {
            int sum = 0;
            for (int[] h : house) {
                int dist = Integer.MAX_VALUE;
                for (int[] c : selected) {
                    dist = Math.min(dist, Math.abs(h[0] - c[0]) + Math.abs(h[1] - c[1]));
                }
                sum += dist;
            }
            answer = Math.min(answer, sum);
            return;
        }
        for (int i = start; i < chicken.size(); i++) {
            selected.add(chicken.get(i));
            comb(i + 1, depth + 1, selected);
            selected.remove(selected.size() - 1);
        }
    }
}