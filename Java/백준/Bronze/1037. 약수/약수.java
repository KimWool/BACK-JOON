import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int num = s.nextInt(); //입력받을 약수의 개수
        int[] nn = new int[num]; //입력받을 약수들

        //약수 입력받음
        for (int i = 0; i < num; i++) {
            nn[i] = s.nextInt();
        }

        Arrays.sort(nn);

        int N = nn[0] * nn[num - 1];
        System.out.println(N);
    }
}