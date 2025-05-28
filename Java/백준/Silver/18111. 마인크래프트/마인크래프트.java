import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] inputs = br.readLine().split(" ");
        int N = Integer.parseInt(inputs[0]); //가로 N
        int M = Integer.parseInt(inputs[1]); //세로 M의 집터
        int B = Integer.parseInt(inputs[2]); //인벤토리에 들어 있는 블록 수

        int[][] ground = new int[N][M];
        int max = 0; int min = 256;

        for(int i = 0; i < N; i++){
            inputs = br.readLine().split(" ");
            for(int j = 0; j < M; j++){
                ground[i][j] = Integer.parseInt(inputs[j]);
                max = Math.max(max, ground[i][j]);
                min = Math.min(min, ground[i][j]);
            }
        }

        int resultTime = Integer.MAX_VALUE;
        int resultHeight = 0;

        for(int i = min; i <= max; i++){
            int time = 0;
            int inventory = B;
            for(int j = 0; j < N; j++){
                for(int k = 0; k < M; k++){
                    int diff = ground[j][k] - i;
                    if (diff > 0) { //블록 제거
                        time += diff * 2;
                        inventory += diff;
                    } else if (diff < 0) { //블록 추가
                        time += (-diff);
                        inventory -= (-diff);
                    }
                }
            }

            if (inventory >= 0){
                if (time < resultTime || (time == resultTime && i > resultHeight)){
                    resultTime = time;
                    resultHeight = i;
                }
            }
        }

        System.out.print(resultTime + " " + resultHeight);
    }
}