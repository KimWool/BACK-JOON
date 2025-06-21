import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Dictionary;
import java.util.Hashtable;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        Dictionary<String, String> dict = new Hashtable<>();
        dict.put("M", "MatKor");
        dict.put("W", "WiCys");
        dict.put("C", "CyKor");
        dict.put("A", "AlKor");
        dict.put("$", "$clear");

        String line = br.readLine();
        System.out.print(dict.get(line));
    }
}