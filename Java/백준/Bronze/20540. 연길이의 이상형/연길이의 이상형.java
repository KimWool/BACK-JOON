import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        String mbti = br.readLine();

        if (mbti.charAt(0) == 'E') {
            sb.append("I");
        } else {
            sb.append("E");
        }

        if (mbti.charAt(1) == 'S') {
            sb.append("N");
        } else {
            sb.append("S");
        }

        if (mbti.charAt(2) == 'T') {
            sb.append("F");
        } else {
            sb.append("T");
        }

        if (mbti.charAt(3) == 'J') {
            sb.append("P");
        } else {
            sb.append("J");
        }

        System.out.print(sb);
    }
}