import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]); //지하철 승강장까지 걸어가는 데 걸리는 시간
        int A = Integer.parseInt(input[1]); //마지막 버스가 도착하는 시간
        int B = Integer.parseInt(input[2]); //마지막 열차가 도착하는 시간

        if (A < B) {
            System.out.print("Bus");
        } else if (A > B) {
            System.out.print("Subway");
        } else {
            System.out.print("Anything");
        }
    }
}