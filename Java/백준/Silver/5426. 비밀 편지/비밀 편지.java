import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        
        int t = Integer.parseInt(br.readLine());
        
        while (t-- > 0) {
            String s = br.readLine();
            int n = (int) Math.sqrt(s.length());
            for (int j = n - 1; j >= 0; j--) {
                for (int i = 0; i < n; i++) {
                    sb.append(s.charAt(i * n + j));
                }
            }
            sb.append('\n');
        }
        
        System.out.print(sb);
    }
}