import java.util.Scanner;

public class Main {
    static int[] dp = new int[11];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        
        for (int i = 4; i <= 10; i++) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }

        for (int i = 0; i < T; i++) {
            int n = scanner.nextInt();
            System.out.println(dp[n]);
        }

        scanner.close();
    }
}
