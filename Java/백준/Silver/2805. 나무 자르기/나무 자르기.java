import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N, M;
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]); //나무의 수
        M = Integer.parseInt(input[1]); //집으로 가져가려고 하는 나무의 길이

        int max = 0;
        int[] length = new int[N];

        String[] lengths = br.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            length[i] = Integer.parseInt(lengths[i]);
            if (length[i] > max) {
                max = length[i];
            }
        }

        int answer = getAnswer(max, length, M);

        System.out.print(answer);
    }

    private static int getAnswer(int max, int[] length, int M) {
        int low = 0;
        int high = max;
        int answer = 0;

        while (low <= high) {
            int mid = (low + high) / 2;

            long sum = 0;
            for (int tree : length) {
                if (tree > mid) {
                    sum += tree - mid;
                }
            }

            if (sum >= M) { //길이가 충분하거나 초과한 경우
                answer = mid;
                low = mid + 1;
            } else { //길이가 모자란 경우
                high = mid - 1;
            }
        }
        return answer;
    }
}