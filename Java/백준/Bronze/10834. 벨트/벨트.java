import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int M = Integer.parseInt(br.readLine());
        
        BigInteger num = BigInteger.ONE;
        BigInteger den = BigInteger.ONE;
        boolean isClock = true;
        StringTokenizer st;
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            BigInteger a = new BigInteger(st.nextToken());
            BigInteger b = new BigInteger(st.nextToken());
            int s = Integer.parseInt(st.nextToken());
            
            if (s == 1) isClock = !isClock;
            
            BigInteger g1 = num.gcd(a);
            num = num.divide(g1);
            a   = a.divide(g1);
            BigInteger g2 = b.gcd(den);
            b   = b.divide(g2);
            den = den.divide(g2);
            
            num = num.multiply(b);
            den = den.multiply(a);
        }
        
        BigInteger res = num.divide(den);
        int direction = isClock ? 0 : 1;
        System.out.println(direction + " " + res.toString());
    }
}