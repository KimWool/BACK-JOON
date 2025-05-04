import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N, M;

        String input[] = br.readLine().split(" ");
        N = Integer.parseInt(input[0]); //도감에 수록되어 있는 포켓몬의 개수
        M = Integer.parseInt(input[1]); //맞춰야 하는 문제의 개수

        HashMap<Integer, String> intToString = new HashMap<>();
        HashMap<String, Integer> stringToInt = new HashMap<>();

        //포켓몬 도감 채우기
        for (int i = 1; i <= N; i++) {
            String pokemon = br.readLine();
            intToString.put(i, pokemon);
        }

        for (Integer key : intToString.keySet()) {
            stringToInt.put(intToString.get(key), key);
        }

        //맞춰야 하는 문제 입력
        for (int i = 0; i < M; i++) {
            String question = br.readLine();
            if (question.matches("\\d+")) { //번호가 입력된 경우
                int number = Integer.parseInt(question);
                String pokemon = intToString.get(number);
                System.out.println(pokemon);
            } else {
                int number = stringToInt.get(question);
                System.out.println(number);
            }
        }
    }
}