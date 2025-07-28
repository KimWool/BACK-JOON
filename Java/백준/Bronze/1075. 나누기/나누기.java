import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int F = Integer.parseInt(br.readLine());

        int temp = (N / 100) * 100;
        int result = (temp % F == 0) ? temp : temp + (F - (temp % F));

        System.out.printf("%02d", result % 100);
    }
}