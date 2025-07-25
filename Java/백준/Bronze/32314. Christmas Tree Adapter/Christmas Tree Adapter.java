import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int a = Integer.parseInt(br.readLine()); //암페어

        String[] input = br.readLine().split(" ");
        int w = Integer.parseInt(input[0]); //와트
        int v = Integer.parseInt(input[1]); //볼트

        if (w / v >= a) {
            System.out.print(1);
        } else {
            System.out.print(0);
        }
    }
}