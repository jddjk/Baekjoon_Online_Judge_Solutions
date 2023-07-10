import java.util.HashMap;
import java.util.Scanner;

public class Main {
    static HashMap<Long, Long> memo = new HashMap<>(10000);

    static long path(long n, long p, long q) {
        if (n == 0) return 1;
        if (memo.containsKey(n)) return memo.get(n);

        long value = path(n / p, p, q) + path(n / q, p, q);
        memo.put(n, value);
        return value;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        long N = sc.nextLong();
        long P = sc.nextLong();
        long Q = sc.nextLong();

        System.out.println(path(N, P, Q));
    }
}
