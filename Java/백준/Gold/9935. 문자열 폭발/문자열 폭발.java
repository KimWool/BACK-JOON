import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        String bomb = br.readLine();
        StringBuilder sb = new StringBuilder();
        int blen = bomb.length();

        for (int i = 0; i < str.length(); i++) {
            sb.append(str.charAt(i));
            if (sb.length() >= blen) {
                boolean flag = true;
                for (int j = 0; j < blen; j++) {
                    if (sb.charAt(sb.length() - blen + j) != bomb.charAt(j)) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    sb.delete(sb.length() - blen, sb.length());
                }
            }
        }
        System.out.println(sb.length() == 0 ? "FRULA" : sb.toString());
    }
}