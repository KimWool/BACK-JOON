import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        //1부터 1000000까지의 자연수 범위의 F(N) 값을 계산하여 저장한다.
        long[] result = new long[1000001];
        for(int i = 1; i <= 1000000; i++){
            int n = 1;
            result[i] += result[i-1];
            while(i * n <= 1000000){
                result[i * n++] += i;
            }
        }

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int num = 0;

        try {
            num = Integer.parseInt(br.readLine());
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        for(int i = 0; i < num; i++){
            try {
                sb.append(result[Integer.parseInt(br.readLine())]).append("\n");
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        System.out.println(sb);
    }
}