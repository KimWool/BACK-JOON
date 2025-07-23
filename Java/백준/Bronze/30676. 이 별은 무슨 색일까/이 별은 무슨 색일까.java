import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int lambda = Integer.parseInt(br.readLine());

        if (lambda >= 620 && lambda <= 780) {
            System.out.print("Red");
        } else if (lambda >= 590) {
            System.out.print("Orange");
        } else if (lambda >= 570) {
            System.out.print("Yellow");
        } else if (lambda >= 495) {
            System.out.print("Green");
        } else if (lambda >= 450) {
            System.out.print("Blue");
        } else if (lambda >= 425) {
            System.out.print("Indigo");
        } else {
            System.out.print("Violet");
        }
    }
}