import java.io.*;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {

        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

            boolean[] isprime = new boolean[1000001];
            Arrays.fill(isprime, true);
            isprime[0] = isprime[1] = false;

            //에라토스테네스의 체를 이용한 소수 판별
            for (int i = 2; i * i < 1000001; i++) {
                if (isprime[i]) {
                    for (int j = i * i; j < 1000001; j += i) {
                        isprime[j] = false;
                    }
                }
            }

            String line;

            while ((line = br.readLine()) != null){
                int N = Integer.parseInt(line.trim());
                if (N == 0) break; //0이 입력되면 종료된다.

                boolean found = false;

                for (int a = 3; a <= N; a += 2){
                    int b = N - a;
                    if (isprime[a] && isprime[b]) {
                        bw.write(N + " = " + a + " + " + b);
                        bw.newLine();
                        found = true;
                        break;
                    }
                }

                if (!found){
                    bw.write("Goldbach's conjecture is wrong.");
                    bw.newLine();
                }
            }
            bw.flush();
            bw.close();
            br.close();
        } catch (IOException e) { //입출력 예외 처리
            e.printStackTrace();
        } catch (NumberFormatException e) { //숫자 변환시 예외 처리
            e.printStackTrace();
        }
    }
}