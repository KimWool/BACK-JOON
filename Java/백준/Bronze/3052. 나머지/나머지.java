import java.util.*;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int[] dividend = new int[10];
        List<Integer> remainder = new ArrayList<>();

        for (int i = 0; i < 10; i++) {
            dividend[i] = s.nextInt();
            remainder.add(dividend[i] % 42);
        }

        Set<Integer> remainderSet = new HashSet<>(remainder);
        System.out.print(remainderSet.size());

        s.close();
    }
}