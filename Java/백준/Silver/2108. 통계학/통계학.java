import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine()); //수의 개수
        int sum = 0;

        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(br.readLine());
            sum += arr[i];
        }

        Arrays.sort(arr);

        sb.append(Math.round((double) sum / N)).append("\n"); //산술 평균
        sb.append(arr[(N / 2)]).append("\n"); //중앙값
        sb.append(Mode(N, arr)).append("\n"); //최빈값
        sb.append(arr[N - 1] - arr[0]); //범위

        System.out.print(sb);
    }

    static int Mode(int N, int[] arr) {
        int min = Arrays.stream(arr).min().getAsInt();
        int max = Arrays.stream(arr).max().getAsInt();

        int[] count = new int[max - min + 1];

        for (int i = 0; i < N; i++) {
            count[arr[i] - min]++;
        }

        int maxCount = 0;
        for (int c : count) {
            if (c > maxCount) {
                maxCount = c;
            }
        }

        List<Integer> modes = new ArrayList<>();
        for (int i = 0; i < count.length; i++) {
            if (count[i] == maxCount) {
                modes.add(i + min);
            }
        }

        Collections.sort(modes);

        if (modes.size() >= 2) {
            return modes.get(1); //두 번째로 작은 최빈값
        } else {
            return modes.get(0); //가장 작은 최빈값
        }
    }
}