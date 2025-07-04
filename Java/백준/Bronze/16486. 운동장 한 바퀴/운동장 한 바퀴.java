import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int d1 = Integer.parseInt(br.readLine()); //영역 C의 가로의 길이
        int d2 = Integer.parseInt(br.readLine()); //영역 A의 반지름의 길이

        float pie = 3.141592F;
        float length = (2 * d1) + (d2 * 2 * pie);

        System.out.print(length);
    }
}