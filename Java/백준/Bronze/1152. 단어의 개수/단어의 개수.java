import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        String words = s.nextLine().trim(); //앞뒤 공백 제거
        if (words.isEmpty()) {
            System.out.print(0);
        } else { //연속된 공백 처리
            System.out.print(words.split("\\s+").length);
        }

        s.close();
    }
}