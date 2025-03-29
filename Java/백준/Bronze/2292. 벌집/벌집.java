import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int N = s.nextInt(); //방 번호
        int term = 1, cycle = 1;

        while (term < N) {
            term += 6 * cycle;
            cycle++;
        }

        System.out.print(cycle);

        s.close();
    }
}