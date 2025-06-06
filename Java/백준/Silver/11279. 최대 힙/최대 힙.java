import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine()); //연산의 개수
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());

        for(int i = 0; i < N; i++){
            int x = Integer.parseInt(br.readLine());
            if(x > 0){
                maxHeap.add(x);
            } else {
                if(maxHeap.isEmpty()){
                    System.out.println(0);
                    continue;
                }
                System.out.println(maxHeap.poll());
            }
        }
    }
}