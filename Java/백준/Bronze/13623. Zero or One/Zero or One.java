import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String[] values = br.readLine().split(" ");
        int A = Integer.parseInt(values[0]);
        int B = Integer.parseInt(values[1]);
        int C = Integer.parseInt(values[2]);

        if (A != B && A != C && B == C) {
            System.out.print("A");
        } else if (B != A && B != C && A == C) {
            System.out.print("B");
        } else if (C != A && C != B && A == B) {
            System.out.print("C");
        } else {
            System.out.print("*");
        }
    }
}