import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine()); //문자열 S의 길이
        String S = br.readLine();

        int count = 0;
        int i = 0;
        int patternLength = 2 * N + 1;

        while (i <= M - patternLength) {
            boolean isPattern = true;
            for (int j = 0; j < patternLength; j++) {
                if ((j % 2 == 0 && S.charAt(i + j) != 'I') || (j % 2 == 1 && S.charAt(i + j) != 'O')) {
                    isPattern = false;
                    break;
                }
            }

            if (isPattern) {
                count++;
                i += 2; //겹치는 패턴 고려
            } else {
                i++; //다음 문자로 이동
            }
        }

        System.out.print(count);
    }
}