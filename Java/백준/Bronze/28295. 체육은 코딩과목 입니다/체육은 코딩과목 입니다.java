import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int direction = 0;

        int[] command = new int[10];
        for (int i = 0; i < command.length; i++) {
            command[i] = Integer.parseInt(br.readLine());
            switch (command[i]) {
                case 1: //우향우
                    direction += 1;
                    break;
                case 2: //뒤로 돌아
                    direction += 2;
                    break;
                case 3: //좌향좌
                    direction += 3;
                    break;
            }
        }

        direction = direction % 4;
        switch (direction) {
            case 0:
                System.out.print("N");
                break;
            case 1:
                System.out.print("E");
                break;
            case 2:
                System.out.print("S");
                break;
            case 3:
                System.out.print("W");
                break;
        }
    }
}