import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        long number = Long.parseLong(bufferedReader.readLine());

        long result = calculateEulerPhi(number);
        System.out.println(result);
    }

    private static long calculateEulerPhi(long number) {
        long result = number;
        for (long i = 2; i * i <= number; i++) {
            if (number % i == 0) {
                while (number % i == 0) {
                    number /= i;
                }
                result -= result / i;
            }
        }
        if (number > 1) {
            result -= result / number;
        }
        return result;
    }
}
