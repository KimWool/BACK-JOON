import java.io.*;
import java.util.*;

public class Main {
    static class State implements Comparable<State> {
        int[] arr;
        int cost;

        State(int[] arr, int cost) {
            this.arr = Arrays.copyOf(arr, arr.length);
            this.cost = cost;
        }

        @Override
        public int compareTo(State o) {
            return Integer.compare(this.cost, o.cost);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] A = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }

        int M = Integer.parseInt(br.readLine());
        int[][] ops = new int[M][3];
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            ops[i][0] = Integer.parseInt(st.nextToken()) - 1;
            ops[i][1] = Integer.parseInt(st.nextToken()) - 1;
            ops[i][2] = Integer.parseInt(st.nextToken());
        }

        int[] target = A.clone();
        Arrays.sort(target);
        PriorityQueue<State> pq = new PriorityQueue<>();
        Map<String, Integer> dist = new HashMap<>();

        pq.add(new State(A, 0));
        dist.put(Arrays.toString(A), 0);

        while (!pq.isEmpty()) {
            State cur = pq.poll();
            String key = Arrays.toString(cur.arr);

            if (Arrays.equals(cur.arr, target)) {
                System.out.println(cur.cost);
                return;
            }

            for (int[] op : ops) {
                int l = op[0], r = op[1], c = op[2];
                int[] nextArr = cur.arr.clone();
                int temp = nextArr[l];
                nextArr[l] = nextArr[r];
                nextArr[r] = temp;
                int newCost = cur.cost + c;
                String nextKey = Arrays.toString(nextArr);

                if (!dist.containsKey(nextKey) || dist.get(nextKey) > newCost) {
                    dist.put(nextKey, newCost);
                    pq.add(new State(nextArr, newCost));
                }
            }
        }

        System.out.println(-1);
    }
}