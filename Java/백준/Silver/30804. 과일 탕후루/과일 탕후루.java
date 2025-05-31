import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        Integer[] fruits = new Integer[N];
        String[] line = br.readLine().split(" ");

        for (int i = 0; i < N; i++) {
            fruits[i] = Integer.parseInt(line[i]);
        }

        int[] count = new int[10];
        int left = 0, right = 0;
        int kind = 0;
        int maxLength = 0;

        while (right < N) {
            if (count[fruits[right]] == 0) kind++;
            count[fruits[right]]++;
            right++;

            while (kind > 2) {
                count[fruits[left]]--;
                if (count[fruits[left]] == 0) kind--;
                left++;
            }

            maxLength = Math.max(maxLength, right - left);
        }

        System.out.print(maxLength);
    }
}