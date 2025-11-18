import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(st.nextToken());
        }

        ArrayList<Integer> list = new ArrayList<>();
        list.add(a[0]);

        for (int i = 1; i < n; i++) {
            if (a[i] > list.get(list.size() - 1)) {
                list.add(a[i]);
            } else {
                int left = 0;
                int right = list.size() - 1;
                while (left < right) {
                    int mid = (left + right) / 2;
                    if (list.get(mid) < a[i]) {
                        left = mid + 1;
                    } else {
                        right = mid;
                    }
                }
                list.set(left, a[i]);
            }
        }

        System.out.println(list.size());
    }
}