import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        //난쟁이들의 키 입력받기
        int[] heights = new int[9];
        int total = 0;
        for (int i = 0; i < heights.length; i++) {
            heights[i] = s.nextInt();
            total += heights[i];
        }

        s.close();

        int diff = total - 100;

        outer:
        for (int i = 0; i < heights.length; i++) {
            for (int j = i + 1; j < heights.length; j++) {
                if (heights[i] + heights[j] == diff) {
                    heights[i] = heights[j] = 0;
                    break outer;
                }
            }
        }

        Arrays.sort(heights);

        for (int i = 2; i < heights.length; i++) {
            System.out.println(heights[i]);
        }

    }
}