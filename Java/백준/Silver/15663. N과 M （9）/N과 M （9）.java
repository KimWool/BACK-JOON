import java.io.*;
import java.util.*;

public class Main {
    static int N, M;
    static int[] arr;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] nm = br.readLine().split(" ");
        N = Integer.parseInt(nm[0]);
        M = Integer.parseInt(nm[1]);
        
        arr = Arrays.stream(br.readLine().split(" "))
                    .mapToInt(Integer::parseInt)
                    .toArray();
        
        Arrays.sort(arr);
        
        visited = new boolean[N];
        
        backtrack(0, new ArrayList<>());
    }

    public static void backtrack(int depth, List<Integer> currentSequence) {
        if (depth == M) {
            System.out.println(String.join(" ", currentSequence.stream()
                                                            .map(String::valueOf)
                                                            .toArray(String[]::new)));
            return;
        }

        for (int i = 0; i < N; i++) {
            if (i > 0 && arr[i] == arr[i - 1] && !visited[i - 1]) {
                continue;
            }

            if (!visited[i]) {
                visited[i] = true;
                currentSequence.add(arr[i]);
                backtrack(depth + 1, currentSequence);
                currentSequence.remove(currentSequence.size() - 1);
                visited[i] = false;
            }
        }
    }
}