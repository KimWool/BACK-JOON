import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int N = s.nextInt(); //단어의 개수
        s.nextLine();

        Set<String> words = new TreeSet<>((a, b) -> {
            if (a.length() != b.length()){
                return Integer.compare(a.length(), b.length());
            } else {
                return a.compareTo(b); //사전 순으로 정렬
            }
        });

        for (int i = 0; i < N; i++) {
            words.add(s.nextLine());
        }

        for (String word : words) {
            System.out.println(word);
        }
    }
}