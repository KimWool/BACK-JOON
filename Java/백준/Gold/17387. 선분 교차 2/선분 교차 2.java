import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static class Point {
        long x, y;

        Point(long x, long y) {
            this.x = x;
            this.y = y;
        }
    }

    static int ccw(Point a, Point b, Point c) {
        long op = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
        if (op > 0) return 1;
        if (op < 0) return -1;
        return 0;
    }

    static boolean isOverlapping(Point a, Point b, Point c, Point d) {
        return Math.min(a.x, b.x) <= Math.max(c.x, d.x) &&
               Math.max(a.x, b.x) >= Math.min(c.x, d.x) &&
               Math.min(a.y, b.y) <= Math.max(c.y, d.y) &&
               Math.max(a.y, b.y) >= Math.min(c.y, d.y);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        long x1 = Long.parseLong(st.nextToken());
        long y1 = Long.parseLong(st.nextToken());
        long x2 = Long.parseLong(st.nextToken());
        long y2 = Long.parseLong(st.nextToken());

        st = new StringTokenizer(br.readLine());
        long x3 = Long.parseLong(st.nextToken());
        long y3 = Long.parseLong(st.nextToken());
        long x4 = Long.parseLong(st.nextToken());
        long y4 = Long.parseLong(st.nextToken());

        Point A = new Point(x1, y1);
        Point B = new Point(x2, y2);
        Point C = new Point(x3, y3);
        Point D = new Point(x4, y4);

        int ab_c = ccw(A, B, C);
        int ab_d = ccw(A, B, D);
        int cd_a = ccw(C, D, A);
        int cd_b = ccw(C, D, B);

        if (ab_c * ab_d == 0 && cd_a * cd_b == 0) {
            if (isOverlapping(A, B, C, D)) {
                System.out.println(1);
            } else {
                System.out.println(0);
            }
        } else {
            if (ab_c * ab_d <= 0 && cd_a * cd_b <= 0) {
                System.out.println(1);
            } else {
                System.out.println(0);
            }
        }
    }
}