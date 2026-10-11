import java.lang.*;
public class LeapYear {
    public static void main(String[] args) {
        for (int year = 1947; year <= 2050; year++) {
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                System.out.println(year);
            }
        }
    }
}
