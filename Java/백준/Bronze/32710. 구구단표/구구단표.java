import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int N = Integer.parseInt(br.readLine());
        
        boolean check = false;
        
        for (int i = 2; i < 10; i++) {
            if (!check) {
                for (int j = 1; j < 10; j++) {
                    int[] table = {i, j, i * j};
                    for (int value : table) {
                        if (value == N) {
                            check = true;
                            break;
                        }
                    }
                    if (check) {
                        break;
                    }
                }
            } else {
                break;
            }
        }
        
        if (check) {
            System.out.print(1);
        } else {
            System.out.print(0);
        }
    }
}