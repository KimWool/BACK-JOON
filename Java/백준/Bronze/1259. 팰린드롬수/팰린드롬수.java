import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        while(true) {
            int n = s.nextInt();
            if (n == 0) { break; }
            List<Integer> list = new ArrayList<>();
            List<Integer> reverse = new ArrayList<>();
            while (n > 0) {
                list.add(n % 10);
                n /= 10;
            }
            for (int i = list.size(); i > 0; i--) {
                reverse.add(list.get(i - 1));
            }
            if (reverse.equals(list)) {
                System.out.println("yes");
            } else {
                System.out.println("no");
            }
        }

        s.close();
    }
}