import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int A = Integer.parseInt(input[0]); //경쟁사 제품의 가격
        int B = Integer.parseInt(input[1]); //경쟁사 제품의 성능
        int C = Integer.parseInt(input[2]); //WARBOY 가격

        int performance = B / A;
        System.out.print(performance * C * 3);
    }
}