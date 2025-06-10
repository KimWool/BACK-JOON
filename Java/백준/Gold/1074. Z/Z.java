import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static int r, c;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        r = Integer.parseInt(input[1]); //r행
        c = Integer.parseInt(input[2]); //c열

        int size = (int) Math.pow(2, N);
        System.out.print(Z(size, 0, 0));
    }

    public static int Z(int size, int x, int y) {
        if (size == 1) {
            return 0;
        }

        int half = size / 2;
        int area = half * half;

        if (r < x + half && c < y + half) { //1사분면
            return Z(half, x, y);
        } else if (r < x + half && c >= y + half) { //2사분면
            return area + Z(half, x, y + half);
        } else if (r >= x + half && c < y + half) { //3사분면
            return 2 * area + Z(half, x + half, y);
        } else { //4사분면
            return 3 * area + Z(half, x + half, y + half);
        }
    }
}