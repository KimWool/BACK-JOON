import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);

        int nRow = getRow(N);
        int nCol = getCol(N);
        int mRow = getRow(M);
        int mCol = getCol(M);

        int distance = Math.abs(nRow - mRow) + Math.abs(nCol - mCol);
        System.out.println(distance);
    }

    public static int getRow(int num) {
        return (num - 1) / 4 + 1;
    }

    public static int getCol(int num) {
        return (num - 1) % 4 + 1;
    }
}