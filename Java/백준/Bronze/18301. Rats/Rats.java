import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tokens = br.readLine().split(" ");
        
        int n1 = Integer.parseInt(tokens[0]);
        int n2 = Integer.parseInt(tokens[1]);
        int n12 = Integer.parseInt(tokens[2]);

        int N = (int) Math.floor((double)(n1 + 1) * (n2 + 1) / (n12 + 1) - 1);
        System.out.print(N);
    }
}