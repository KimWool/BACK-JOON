import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int N = s.nextInt(); //이동하고자 하는 채널
        int M = s.nextInt(); //고장난 버튼의 개수

        int[] button = new int[M]; //고장난 버튼
        for (int i = 0; i < M; i++) {
            button[i] = s.nextInt();
        }

        int minClicks = Math.abs(100 - N);

        for (int i = 0; i < 1000001; i++) { //채널은 무한대 만큼 있음
            if (validChannel(i, button)) {
                int clicks = String.valueOf(i).length() + Math.abs(N - i);
                minClicks = Math.min(minClicks, clicks);
            }
        }

        System.out.println(minClicks);
    }

    public static boolean validChannel(int N, int[] button) {
        String nString = String.valueOf(N);
        for (int i = 0; i < nString.length(); i++) {
            int digit = nString.charAt(i) - '0';
            for (int j = 0; j < button.length; j++) {
                if (digit == button[j]) {
                    return false;
                }
            }
        }
        return true;
    }
}