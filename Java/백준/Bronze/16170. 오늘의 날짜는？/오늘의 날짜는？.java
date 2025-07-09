import java.time.LocalDate;

public class Main {
    public static void main(String[] args) {
        LocalDate currentDate = LocalDate.now();
        System.out.println(currentDate.getYear());
        System.out.printf("%02d%n", currentDate.getMonthValue());
        System.out.printf("%02d", currentDate.getDayOfMonth());
    }
}