import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int caseNum = 1;

        while (true) {
            String original = br.readLine();
            String received = br.readLine();
            
            if (original.equals("END") && received.equals("END")) {
                break;
            }

            if (isSame(original, received)) {
                System.out.println("Case " + caseNum + ": same");
            } else {
                System.out.println("Case " + caseNum + ": different");
            }

            caseNum++;
        }
    }

    private static boolean isSame(String original, String received) {
        int[] originalFreq = new int[26];
        int[] receivedFreq = new int[26];

        for (int i = 0; i < original.length(); i++) {
            originalFreq[original.charAt(i) - 'a']++;
        }

        for (int i = 0; i < received.length(); i++) {
            receivedFreq[received.charAt(i) - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (originalFreq[i] != receivedFreq[i]) {
                return false;
            }
        }

        return true;
    }
}