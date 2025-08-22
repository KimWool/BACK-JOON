import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        while (true) {
            line = br.readLine();
            String[] parts = line.split(" ");
            int balance = Integer.parseInt(parts[0]);
            String type = parts[1];
            int amount = Integer.parseInt(parts[2]);

            if (balance == 0 && type.equals("W") && amount == 0) {
                break;
            }

            if (type.equals("W")) {
                if (balance - amount < -200) {
                    System.out.println("Not allowed");
                } else {
                    balance -= amount;
                    System.out.println(balance);
                }
            } else if (type.equals("D")) {
                balance += amount;
                System.out.println(balance);
            }
        }
    }
}