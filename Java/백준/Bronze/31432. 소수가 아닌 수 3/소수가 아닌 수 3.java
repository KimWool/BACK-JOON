import java.io.*;
import java.util.*;

public class Main {
    
    static Set<Character> allowedDigits = new HashSet<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String[] digits = br.readLine().split(" ");

        for (String d : digits) {
            allowedDigits.add(d.charAt(0));
        }

        if (canMake("1")) {
            System.out.println("YES");
            System.out.println("1");
            return;
        }

        String[] singleNonPrimes = {"0", "1", "4", "6", "8", "9"};
        for (String s : singleNonPrimes) {
            if (canMake(s)) {
                System.out.println("YES");
                System.out.println(s);
                return;
            }
        }

        for (int len = 1; len <= 4; len++) {
            List<String> candidates = generateNumbers(len);
            for (String numStr : candidates) {
                if (!isPrime(Long.parseLong(numStr))) {
                    System.out.println("YES");
                    System.out.println(numStr);
                    return;
                }
            }
        }

        System.out.println("NO");
    }

    static boolean canMake(String number) {
        for (char c : number.toCharArray()) {
            if (!allowedDigits.contains(c)) {
                return false;
            }
        }
        return true;
    }

    static List<String> generateNumbers(int length) {
        List<String> result = new ArrayList<>();
        generate("", length, result);
        return result;
    }

    static void generate(String current, int length, List<String> result) {
        if (current.length() == length) {
            if (!(current.startsWith("0") && current.length() > 1)) {
                result.add(current);
            }
            return;
        }

        for (char d : allowedDigits) {
            generate(current + d, length, result);
        }
    }

    static boolean isPrime(long n) {
        if (n < 2) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;

        long sqrtN = (long) Math.sqrt(n) + 1;
        for (long i = 5; i <= sqrtN; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }
}