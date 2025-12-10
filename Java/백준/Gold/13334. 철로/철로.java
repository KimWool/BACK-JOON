import java.io.*;
import java.util.*;

public class Main {
    static class Person {
        int start, end;

        Person(int a, int b) {
            this.start = Math.min(a, b);
            this.end = Math.max(a, b);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        Person[] people = new Person[n];

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int h = Integer.parseInt(st.nextToken());
            int o = Integer.parseInt(st.nextToken());
            people[i] = new Person(h, o);
        }

        int d = Integer.parseInt(br.readLine());

        List<Person> validPeople = new ArrayList<>();
        for (Person p : people) {
            if (p.end - p.start <= d) {
                validPeople.add(p);
            }
        }

        Collections.sort(validPeople, Comparator.comparingInt(p -> p.end));

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int answer = 0;

        for (Person p : validPeople) {
            int startRange = p.end - d;
            pq.offer(p.start);

            while (!pq.isEmpty() && pq.peek() < startRange) {
                pq.poll();
            }

            answer = Math.max(answer, pq.size());
        }

        System.out.println(answer);
    }
}