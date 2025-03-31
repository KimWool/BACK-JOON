import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int L = s.nextInt(); //문자열의 길이
        s.nextLine();

        String string = s.nextLine(); //문자열

        char[] chars = string.toCharArray();
        int[] numbers = new int[L];
        int hash = 0;
        for (int i = 0; i < L; i++) {
            numbers[i] = (int) chars[i] - 96;
            hash += (numbers[i] * Math.pow(31, i)) % 1234567891;
        }

        System.out.print(hash);

        s.close();
    }
}