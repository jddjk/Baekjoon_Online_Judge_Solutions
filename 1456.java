import java.util.*;

public class Main {
    static final long MAX = 10000001;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Long> primes = new ArrayList<>();
        boolean[] sieve = new boolean[(int)MAX];
        Arrays.fill(sieve, true);
        sieve[0] = sieve[1] = false;

        for (long i = 2; i < MAX; i++) {
            if (sieve[(int)i]) {
                primes.add(i);
                for (long j = 2; i * j < MAX; j++) {
                    sieve[(int)(i*j)] = false;
                }
            }
        }

        long a = sc.nextLong() - 1;
        long b = sc.nextLong();
        long temp;
        int countA = 0, countB = 0;

        for (Long x : primes) {
            temp = x;
            while (temp <= a / x) {
                temp *= x;
                if (temp <= a) countA++;
            }
        }

        for (Long x : primes) {
            temp = x;
            while (temp <= b / x) {
                temp *= x;
                if (temp <= b) countB++;
            }
        }
        System.out.println(countB - countA);
    }
}
