import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long b = sc.nextLong();
        long result = sum(b) - sum(a - 1);
        System.out.println(result);
        sc.close();
    }

    public static long sum(long n) {
        if (n <= 0)
            return 0;

        long[] c = new long[10];
        long s = 1;
        long sum = 0;
        long t, r;

        while (n > 0) {
            t = n / (s * 10);
            r = n % (s * 10);

            for (int i = 0; i < 10; i++)
                c[i] += t * s;

            for (int i = 1; i <= r / s; i++)
                c[i] += s;

            c[(int)((r / s + 1) % 10)] += r % s;
            n -= 9 * s;
            s *= 10;
        }

        for (int i = 1; i < 10; i++)
            sum += i * c[i];

        return sum;
    }
}
