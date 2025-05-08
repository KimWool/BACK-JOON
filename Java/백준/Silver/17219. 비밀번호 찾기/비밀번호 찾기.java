import java.io.*;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N, M;
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]); //저장된 사이트 주소의 수
        M = Integer.parseInt(input[1]); //비밀번호를 찾으려는 사이트 주소의 수

        HashMap<String, String> map = new HashMap<>();
        for (int i = 0; i < N; i++) {
            String[] line = br.readLine().split(" ");
            map.put(line[0], line[1]);
        }

        for (int i = 0; i < M; i++) {
            String site = br.readLine();
            bw.write(map.get(site) + "\n");
        }

        bw.flush();
        bw.close();
    }
}