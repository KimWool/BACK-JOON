import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int L = s.nextInt(); //암호는 서로 다른 L개의 알파벳 소문자들로 구성
        int C = s.nextInt(); //조교들이 암호로 사용했을 법한 문자의 종류 C가지

        char[] alphabet = new char[C];
        for (int i = 0; i < C; i++) {
            alphabet[i] = s.next().charAt(0);
        }

        Arrays.sort(alphabet);
        char[] password = new char[L];

        backtrack(C, L, 0, 0, alphabet, password);

    }

    public static void backtrack(int c, int l, int start, int depth, char[] alphabet, char[] password) {
        if (depth == l){
            int vowel = 0; //모음의 개수
            int consonant = 0; //자음의 개수
            for (int i = 0; i < l; i++) {
                char ch = password[i];
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                    vowel++;
                } else {
                    consonant++;
                }
            }
            if (vowel >= 1 && consonant >= 2) {
                System.out.println(new String(password));
            }
            return;
        }
        for (int i = start; i < c; i++) {
            password[depth] = alphabet[i];
            backtrack(c, l, i + 1, depth + 1, alphabet, password);
        }
    }
}