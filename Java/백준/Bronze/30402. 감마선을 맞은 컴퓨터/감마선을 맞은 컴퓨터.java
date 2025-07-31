import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        char[][] photo = new char[15][15];
        String result = "";

        for (int i = 0; i < 15; i++) {
            String[] line = br.readLine().split(" ");
            for (int j = 0; j < 15; j++) {
                photo[i][j] = line[j].charAt(0);
                if (photo[i][j] == 'w') {
                    result = "chunbae";
                } else if (photo[i][j] == 'b') {
                    result = "nabi";
                } else if (photo[i][j] == 'g') {
                    result = "yeongcheol";
                }
            }
        }

        System.out.print(result);
    }
}