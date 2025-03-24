import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int[] syllable = new int[8];
        for (int i = 0; i < 8; i++) {
            syllable[i] = s.nextInt();
        }

        int[] ascending = {1, 2, 3, 4, 5, 6, 7, 8};
        int[] descending = {8, 7, 6, 5, 4, 3, 2, 1};

        if (Arrays.equals(syllable, ascending)) {
            System.out.print("ascending");
        } else if (Arrays.equals(syllable, descending)) {
            System.out.print("descending");
        } else {
            System.out.print("mixed");
        }

        s.close();
    }
}