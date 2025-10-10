import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int[] A = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        int m = Integer.parseInt(br.readLine());
        int[] B = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        List<Integer> result = new ArrayList<>();

        int ai = 0, bi = 0;
        while (ai < n && bi < m) {
            int maxVal = 0;
            for (int i = ai; i < n; i++) {
                for (int j = bi; j < m; j++) {
                    if (A[i] == B[j]) {
                        maxVal = Math.max(maxVal, A[i]);
                    }
                }
            }
            if (maxVal == 0) break;

            while (ai < n && A[ai] != maxVal) ai++;
            while (bi < m && B[bi] != maxVal) bi++;

            result.add(maxVal);
            ai++;
            bi++;
        }

        bw.write(result.size() + "\n");
        for (int x : result) bw.write(x + " ");
        bw.newLine();
        bw.flush();
    }
}