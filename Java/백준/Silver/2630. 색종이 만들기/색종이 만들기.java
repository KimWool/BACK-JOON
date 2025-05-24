import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static int[][] paper;
    static int white = 0;
    static int blue = 0;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        paper = new int[N][N]; //N*N 크기의 정사각형 모양 종이

        for(int i = 0; i < N; i++){
            String[] split = br.readLine().split(" ");
            for(int j = 0; j < N; j++){
                paper[i][j] = Integer.parseInt(split[j]);
            }
        }

        divide(0, 0, N);

        System.out.println(white);
        System.out.print(blue);
    }

    public static void divide(int row, int column, int size) {
        if(check(row, column, size)){
            if(paper[row][column] == 0){
                white++;
            } else {
                blue++;
            }
            return;
        }
        int newSize = size / 2;
        divide(row, column, newSize); //왼쪽 위
        divide(row, column + newSize, newSize); //오른쪽 위
        divide(row + newSize, column, newSize); //왼쪽 아래
        divide(row + newSize, column + newSize, newSize); //오른쪽 아래
    }

    public static boolean check(int row, int column, int size) {
        int color = paper[row][column];

        for(int i = row; i < row + size; i++){
            for(int j = column; j < column + size; j++){
                if(paper[i][j] != color){
                    return false;
                }
            }
        }
        return true;
    }
}