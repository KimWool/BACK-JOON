import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.HashMap;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static HashMap<Integer, Integer> map;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(br.readLine());

        for (int test = 0; test < t; test++) {
            int input = Integer.parseInt(br.readLine());

            PriorityQueue<Integer> minHeap = new PriorityQueue<>();
            PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
            map = new HashMap<>();

            for (int i = 0; i < input; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                String op = st.nextToken();

                if (op.equals("I")) {
                    int num = Integer.parseInt(st.nextToken());
                    minHeap.add(num);
                    maxHeap.add(num);
                    map.put(num, map.getOrDefault(num, 0) + 1);
                } else {
                    int type = Integer.parseInt(st.nextToken());

                    if (map.isEmpty()) {
                        continue;
                    }

                    if (type == 1) {
                        pollAndClean(maxHeap);
                    } else {
                        pollAndClean(minHeap);
                    }
                }
            }
            
            cleanHeaps(minHeap, maxHeap);

            if (minHeap.isEmpty()) {
                sb.append("EMPTY\n");
            } else {
                sb.append(maxHeap.peek()).append(" ").append(minHeap.peek()).append("\n");
            }
        }
        System.out.println(sb);
    }

    private static void pollAndClean(PriorityQueue<Integer> q) {
        while (!q.isEmpty()) {
            int val = q.peek();
            int count = map.getOrDefault(val, 0);

            q.poll();
            if (count != 0) {
                if (count == 1) {
                    map.remove(val);
                } else {
                    map.put(val, count - 1);
                }
                break;
            }
        }
    }

    private static void cleanHeaps(PriorityQueue<Integer> minHeap, PriorityQueue<Integer> maxHeap) {
        while (!minHeap.isEmpty() && map.getOrDefault(minHeap.peek(), 0) == 0) {
            minHeap.poll();
        }
        while (!maxHeap.isEmpty() && map.getOrDefault(maxHeap.peek(), 0) == 0) {
            maxHeap.poll();
        }
    }
}