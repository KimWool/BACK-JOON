import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int L = s.nextInt(); //문자열의 길이
        s.nextLine();

        String string = s.nextLine(); //문자열

        long hash = 0;
        long pow = 1;
        final int M = 1234567891;
        
        for (int i = 0; i < L; i++) {
            int num = string.charAt(i) - 'a' + 1;
            hash = (hash + (pow * num) % M) % M;
            pow = (pow * 31) % M;
        }

        System.out.print(hash);

        s.close();
    }
}