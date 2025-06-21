import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String line;

        while ((line = br.readLine()) != null) {
            if (line.trim().isEmpty()) { continue; }

            String[] input = line.split(" ");
            int N = Integer.parseInt(input[0]); //N명의 사람들
            int S = Integer.parseInt(input[1]); //S개의 주식

            int people = N + 1; //수석 판사 포함
            System.out.println(S / people);
        }
    }
}