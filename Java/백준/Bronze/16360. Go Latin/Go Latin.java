import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            String word = br.readLine();
            String result = convertToPseudoLatin(word);
            System.out.println(result);
        }
    }

    public static String convertToPseudoLatin(String word) {
        if (word.endsWith("ne")) return word.substring(0, word.length() - 2) + "anes";
        if (word.endsWith("a"))  return word.substring(0, word.length() - 1) + "as";
        if (word.endsWith("i"))  return word.substring(0, word.length() - 1) + "ios";
        if (word.endsWith("y"))  return word.substring(0, word.length() - 1) + "ios";
        if (word.endsWith("l"))  return word.substring(0, word.length() - 1) + "les";
        if (word.endsWith("n"))  return word.substring(0, word.length() - 1) + "anes";
        if (word.endsWith("o"))  return word.substring(0, word.length() - 1) + "os";
        if (word.endsWith("r"))  return word.substring(0, word.length() - 1) + "res";
        if (word.endsWith("t"))  return word.substring(0, word.length() - 1) + "tas";
        if (word.endsWith("u"))  return word.substring(0, word.length() - 1) + "us";
        if (word.endsWith("v"))  return word.substring(0, word.length() - 1) + "ves";
        if (word.endsWith("w"))  return word.substring(0, word.length() - 1) + "was";

        return word + "us";
    }
}