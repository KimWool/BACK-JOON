import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder output = new StringBuilder();

        String[] birthday = br.readLine().split(" ");
        int BYear = Integer.parseInt(birthday[0]);
        int BMonth = Integer.parseInt(birthday[1]);
        int BDay = Integer.parseInt(birthday[2]);

        String[] date = br.readLine().split(" ");
        int DYear = Integer.parseInt(date[0]);
        int DMonth = Integer.parseInt(date[1]);
        int DDay = Integer.parseInt(date[2]);

        if (BMonth > DMonth || (BMonth == DMonth && BDay > DDay)) {
            output.append(DYear - BYear - 1).append("\n");
        } else {
            output.append(DYear - BYear).append("\n");
        }

        output.append(DYear - BYear + 1).append("\n");
        output.append(DYear - BYear);

        System.out.print(output);
    }
}