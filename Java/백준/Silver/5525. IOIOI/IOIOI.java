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
        int pattern = 0; //연결된 "OI"의 개수

        while (i < M - 1) {
            if (S.charAt(i) == 'I' && S.charAt(i + 1) == 'O') {
                int j = i + 1;
                while (j + 1 < M && S.charAt(j) == 'O' && S.charAt(j + 1) == 'I') {
                    pattern++;
                    j += 2;

                    if (pattern == N) {
                        count++;
                        pattern--; //겹치는 패턴 고려
                    }
                }
                i = j; //다음 탐색 위치로 이동
                pattern = 0; //패턴 초기화
            } else {
                i++;
            }
        }

        System.out.print(count);
    }
}