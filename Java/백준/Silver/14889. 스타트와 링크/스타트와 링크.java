import java.util.Scanner;

public class Main {

    static int N;
    static int[][] S;
    static boolean[] isStart;

    static int minStatus = Integer.MAX_VALUE;

public static void main(String[] args) {

    Scanner s = new Scanner(System.in);

    N = s.nextInt(); //축구를 하기 위해 모인 사람
    S = new int[N][N]; //팀에 더해지는 능력치
    isStart = new boolean[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            S[i][j] = s.nextInt();
        }
    }

    backtrack(0, 0);
    System.out.print(minStatus);
    }

    public static void backtrack(int index, int count) {
        if (count == N / 2) {
            difference();
            return;
        }
        for (int i = index; i < N; i++) {
            if (!isStart[i]) {
                isStart[i] = true;
                backtrack(i + 1, count + 1);
                isStart[i] = false;
            }
        }
    }

    public static void difference(){
        int startTeam = 0;
        int linkTeam = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (isStart[i] && isStart[j]) {
                    startTeam += S[i][j];
                } else if (!isStart[i] && !isStart[j]) {
                    linkTeam += S[i][j];
                }
            }
        }

        int diff = Math.abs(startTeam - linkTeam);
        minStatus = Math.min(diff, minStatus);
    }
}