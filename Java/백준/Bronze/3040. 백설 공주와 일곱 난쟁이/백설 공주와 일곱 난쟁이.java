import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int sum = 0;
        int[] numbers = new int[9];
        boolean[] flag = new boolean[9];

        for (int i = 0; i < 9; i++) {
            numbers[i] = Integer.parseInt(br.readLine());
            sum += numbers[i];
            flag[i] = true;
        }

        int difference = sum - 100;
        for (int i = 0; i < 9; i++) {
            for (int j = i + 1; j < 9; j++) {
                if (numbers[j] == difference - numbers[i]) {
                    flag[i] = false;
                    flag[j] = false;
                    break;
                }
            }
        }

        for (int i = 0; i < 9; i++) {
            if (flag[i]) {
                System.out.println(numbers[i]);
            }
        }
    }
}