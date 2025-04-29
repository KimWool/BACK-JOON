import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    public static void main(String[] args) {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N, M;

        try {
            int testCases = Integer.parseInt(br.readLine());
            for (int i = 0; i < testCases; i++) {
                String[] input = br.readLine().split(" ");
                N = Integer.parseInt(input[0]);
                M = Integer.parseInt(input[1]);

                Queue<Document> q = new LinkedList<>();
                String[] queues = br.readLine().split(" ");
                for (int j = 0; j < N; j++) {
                    q.add(new Document(j, Integer.parseInt(queues[j])));
                }

                int count = 0;
                while (!q.isEmpty()) {
                    Document doc = q.poll();
                    boolean hasHigher = false;
                    for (Document d : q) {
                        if (d.priority > doc.priority) {
                            hasHigher = true;
                            break;
                        }
                    }
                    if (hasHigher) {
                        q.add(doc);
                    } else {
                        count++;
                        if (doc.index == M) {
                            System.out.println(count);
                            break;
                        }
                    }
                }
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

    }

    static class Document {
        int index;
        int priority;
        Document(int index, int priority) {
            this.index = index;
            this.priority = priority;
        }
    }
}