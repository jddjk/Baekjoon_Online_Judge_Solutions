import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();

        while (T-- > 0) {
            int M = scanner.nextInt();
            int N = scanner.nextInt();
            int x = scanner.nextInt();
            int y = scanner.nextInt();

            int maxYear = M * N / gcd(M, N);
            int answer = -1;

            while (x <= maxYear) {
                if (x % N == y % N) {
                    answer = x;
                    break;
                }
                x += M;
            }

            System.out.println(answer);
        }
    }

    public static int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
}
