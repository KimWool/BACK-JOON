import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int N = s.nextInt(); //시험 본 과목의 개수
        int[] scores = new int[N]; //현재 성적

        int M = Integer.MIN_VALUE; //점수 최댓값
        float avg = 0; //조작된 점수 평균
        float[] MScores = new float[N]; //조작된 점수

        for (int i = 0; i < N; i++) {
            scores[i] = s.nextInt();
            if (scores[i] > M) {
                M = scores[i];
            }
        }

        for (int i = 0; i < N; i++) {
            MScores[i] = (float) scores[i] / M * 100;
            avg += MScores[i];
        }

        System.out.print(avg / N);

        s.close();
    }
}