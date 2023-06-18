import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        if (N <= 10) {
            System.out.println(N);
        } else if (N > 1022) {
            System.out.println(-1);
        } else {
            Queue<Long> queue = new LinkedList<>();
            for (long i = 1; i <= 9; i++) {
                queue.add(i);
            }
            while (--N > 0) {
                long number = queue.poll();
                long lastDigit = number % 10;
                for (long i = 0; i < lastDigit; i++) {
                    queue.add(number * 10 + i);
                }
            }
            System.out.println(queue.poll());
        }
    }
}
