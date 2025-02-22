import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int E = s.nextInt(); //지구
        int S = s.nextInt(); //태양
        int M = s.nextInt(); //달

        int Earth = 1;
        int Sun = 1;
        int Moon = 1;

        int year = 1;

        while(true){
            if(Earth > 15){ Earth = 1; }
            if(Sun > 28){ Sun = 1; }
            if(Moon > 19){ Moon = 1; }
            if ((Earth == E) && (Sun == S) && (Moon == M)){
                break;
            }
            Earth++;
            Sun++;
            Moon++;
            year++;
        }

        System.out.print(year);
    }
}