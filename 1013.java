import java.util.Scanner;
import java.util.regex.Pattern;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int T = scanner.nextInt();
        scanner.nextLine();

        Pattern pattern = Pattern.compile("^(100+1+|01)+$");

        for (int i = 0; i < T; i++) {
            String input = scanner.nextLine();
            if (pattern.matcher(input).matches()) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }

        scanner.close();
    }
}
