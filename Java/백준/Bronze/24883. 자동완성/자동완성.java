import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String input = br.readLine();

        if (input.equals("N") || input.equals("n")) {
            System.out.print("Naver D2");
        } else {
            System.out.print("Naver Whale");
        }
    }
}