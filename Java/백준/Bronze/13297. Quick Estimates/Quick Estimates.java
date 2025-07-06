import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine()); //테스트 케이스 수
        for (int i = 0; i < N; i++) {
            String price = br.readLine().trim();
            System.out.println(price.length());
        }
    }
}