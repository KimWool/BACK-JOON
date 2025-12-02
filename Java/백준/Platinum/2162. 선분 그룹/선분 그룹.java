import java.io.*;
import java.util.*;

public class Main {
    static int[] parent;
    static int[] count;

    static class Point {
        long x, y;

        Point(long x, long y) {
            this.x = x;
            this.y = y;
        }
    }

    static class Line {
        Point p1, p2;

        Line(Point p1, Point p2) {
            this.p1 = p1;
            this.p2 = p2;
        }
    }

    static int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    static void union(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA != rootB) {
            parent[rootB] = rootA;
            count[rootA] += count[rootB];
        }
    }

    static int ccw(Point a, Point b, Point c) {
        long op = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
        if (op > 0) return 1;
        else if (op < 0) return -1;
        else return 0;
    }

    static boolean isIntersect(Line l1, Line l2) {
        Point a = l1.p1;
        Point b = l1.p2;
        Point c = l2.p1;
        Point d = l2.p2;

        int ab = ccw(a, b, c) * ccw(a, b, d);
        int cd = ccw(c, d, a) * ccw(c, d, b);

        if (ab == 0 && cd == 0) {
            if (Math.min(a.x, b.x) > Math.max(c.x, d.x) || Math.min(c.x, d.x) > Math.max(a.x, b.x))
                return false;
            if (Math.min(a.y, b.y) > Math.max(c.y, d.y) || Math.min(c.y, d.y) > Math.max(a.y, b.y))
                return false;
            return true;
        }

        return ab <= 0 && cd <= 0;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        Line[] lines = new Line[n];
        parent = new int[n];
        count = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            count[i] = 1;
        }

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            long x1 = Long.parseLong(st.nextToken());
            long y1 = Long.parseLong(st.nextToken());
            long x2 = Long.parseLong(st.nextToken());
            long y2 = Long.parseLong(st.nextToken());

            lines[i] = new Line(new Point(x1, y1), new Point(x2, y2));
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isIntersect(lines[i], lines[j])) {
                    union(i, j);
                }
            }
        }

        int groupCount = 0;
        int maxGroupSize = 0;

        for (int i = 0; i < n; i++) {
            if (parent[i] == i) {
                groupCount++;
                maxGroupSize = Math.max(maxGroupSize, count[i]);
            }
        }

        System.out.println(groupCount);
        System.out.println(maxGroupSize);
    }
}