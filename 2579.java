import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        int[] dp = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                dp[i] = arr[i];
            } else if (i == 1) {
                dp[i] = arr[i] + arr[i - 1];
            } else if (i == 2) {
                dp[i] = Math.max(arr[i - 1], arr[i - 2]) + arr[i];
            } else {
                dp[i] = Math.max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]);
            }
        }

        System.out.println(dp[n - 1]);
    }
}
