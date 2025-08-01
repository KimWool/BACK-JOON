import java.io.*;
import java.util.Hashtable;
import java.util.Map;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String S = br.readLine();

        Map<Character, Integer> map = new Hashtable<>() {{
            put('A', 1);
            put('a', 1);
            put('B', 2);
            put('b', 1);
            put('D', 1);
            put('d', 1);
            put('e', 1);
            put('g', 1);
            put('O', 1);
            put('o', 1);
            put('P', 1);
            put('p', 1);
            put('Q', 1);
            put('q', 1);
            put('R', 1);
            put('@', 1);
        }};

        int holes = 0;
        for (int i = 0; i < S.length(); i++) {
            holes += map.getOrDefault(S.charAt(i), 0);
        }

        System.out.print(holes);
    }
}