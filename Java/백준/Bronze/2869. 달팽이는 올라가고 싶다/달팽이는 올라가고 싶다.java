import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int A = s.nextInt(); //낮에 A미터 올라갈 수 있다
        int B = s.nextInt(); //밤에 잠을 자는 동안 B미터 미끄러진다
        int V = s.nextInt(); //높이가 V미터인 나무 막대

        int day = (V - A) / (A - B);
        if ((V - A) % (A - B) != 0) {
            day++;
        }

        System.out.print(day + 1);

        s.close();
    }
}