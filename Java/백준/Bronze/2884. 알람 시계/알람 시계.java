import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        //H시 M분
        int H = s.nextInt();
        int M = s.nextInt();

        M -= 45;
        if (M < 0){
            H--;
            M += 60;
            if (H < 0){
                H += 24;
            }
        }

        System.out.print(H + " " + M);

        s.close();
    }
}