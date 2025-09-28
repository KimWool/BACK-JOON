import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    static char[][] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        arr = new char[N][2 * N - 1];

        // 배열을 공백으로 초기화
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 2 * N - 1; j++) {
                arr[i][j] = ' ';
            }
        }

        drawStar(0, N - 1, N);

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < N; i++) {
            sb.append(arr[i]).append("\n");
        }
        System.out.print(sb);
    }

    static void drawStar(int x, int y, int size) {
        if (size == 3) {
            arr[x][y] = '*';
            arr[x + 1][y - 1] = '*';
            arr[x + 1][y + 1] = '*';
            for (int i = -2; i <= 2; i++) {
                arr[x + 2][y + i] = '*';
            }
            return;
        }

        int newSize = size / 2;
        drawStar(x, y, newSize); // 위 삼각형
        drawStar(x + newSize, y - newSize, newSize); // 왼쪽 아래 삼각형
        drawStar(x + newSize, y + newSize, newSize); // 오른쪽 아래 삼각형
    }
}