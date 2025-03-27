import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        String S = s.nextLine(); //단어 S
        int[] alphabet = new int[26];
        boolean[] used = new boolean[26];
        for (int i = 0; i < 26; i++) {
            alphabet[i] = -1;
            used[i] = false;
        }

        for (int i = 0; i < S.length(); i++) {
            for (int j = 97; j <= 122; j++) { //소문자 a-z
                if ((S.charAt(i) == (char) j) && (!used[j - 97])) {
                    alphabet[j - 97] = i;
                    used[j - 97] = true;
                }
            }
        }

        for (int i = 0; i < alphabet.length; i++) {
            System.out.print(alphabet[i] + " ");
        }

        s.close();
    }
}