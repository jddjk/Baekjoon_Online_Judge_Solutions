import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        
        for (int t = 0; t < T; t++) {
            int x1 = sc.nextInt();
            int y1 = sc.nextInt();
            int x2 = sc.nextInt();
            int y2 = sc.nextInt();
            int n = sc.nextInt();

            int enter = 0;
            int departure = 0;

            for (int i = 0; i < n; i++) {
                int cx = sc.nextInt();
                int cy = sc.nextInt();
                int r = sc.nextInt();


                boolean startInside = isInside(x1, y1, cx, cy, r);
                boolean endInside = isInside(x2, y2, cx, cy, r);


                if (startInside != endInside) {
                    if (startInside) {
                        departure++;
                    } else {
                        enter++;
                    }
                }
            }

            int count = enter + departure;
            System.out.println(count);
        }
    }

    private static boolean isInside(int x, int y, int cx, int cy, int r) {
        int dx = x - cx;
        int dy = y - cy;
        int distanceSquared = dx * dx + dy * dy;

        return distanceSquared < r * r;
    }
}
