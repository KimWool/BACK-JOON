import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] firstLine = br.readLine().split(" ");
        
        int N = Integer.parseInt(firstLine[0]);
        int M = Integer.parseInt(firstLine[1]);
        
        int[] friendsCount = new int[N + 1];
        
        for (int i = 0; i < M; i++) {
            String[] relation = br.readLine().split(" ");
            int A = Integer.parseInt(relation[0]);
            int B = Integer.parseInt(relation[1]);
            
            friendsCount[A]++;
            friendsCount[B]++;
        }
        
        for (int i = 1; i <= N; i++) {
            System.out.println(friendsCount[i]);
        }
    }
}