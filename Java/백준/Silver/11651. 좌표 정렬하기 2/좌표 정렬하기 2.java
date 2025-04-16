import java.io.*;
import java.util.Arrays;
import java.util.Comparator;

public class Main {

    public static class Point{
        int x;
        int y;
        Point(int x, int y){
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N;
        try {
            N = Integer.parseInt(br.readLine()); //점의 개수
            Point[] points = new Point[N];
            for (int i = 0; i < N; i++) {
                String[] input = br.readLine().split(" ");
                int x = Integer.parseInt(input[0]);
                int y = Integer.parseInt(input[1]);
                points[i] = new Point(x, y);
            }

            Arrays.sort(points, Comparator.comparingInt((Point p) -> p.y).thenComparingInt(p -> p.x));

            for (Point p : points) {
                System.out.println(p.x + " " + p.y);
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}