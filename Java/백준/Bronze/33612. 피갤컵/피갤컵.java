import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine()); //N회 피갤컵

        int year = 2024; //1회 피갤컵
        int month = 8; //1회 피갤컵

        month += (N - 1) * 7; //7개월 주기로 열림
        while (month > 12) {
            month -= 12;
            year++;
        }

        System.out.print(year + " " + month);
    }
}