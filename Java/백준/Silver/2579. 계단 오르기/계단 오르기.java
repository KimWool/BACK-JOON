import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int stairs = Integer.parseInt(br.readLine()); //계단의 개수

        int[] dp = new int[stairs + 1];
        int[] sum = new int[stairs + 1];

        for(int i = 1; i <= stairs; i++){
            sum[i] = Integer.parseInt(br.readLine());
        }

        dp[1] = sum[1];
        if (stairs >= 2){
            dp[2] = sum[1] + sum[2];
        }
        if (stairs >= 3){
            for(int i = 3; i <= stairs; i++){
                dp[i] = Math.max(dp[i - 2] + sum[i], dp[i - 3] + sum[i - 1] + sum[i]);
            }
        }

        System.out.print(dp[stairs]);
    }
}