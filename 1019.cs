using System;

class MainClass {
    static void Main(string[] args) {
        int[] ans = new int[10];
        int point = 1;
        int start = 1;

        int page = int.Parse(Console.ReadLine());

        while (start <= page) {
            while (page % 10 != 9 && start <= page) {
                Cal(page, ans, point);
                page--;
            }

            if (page < start) {
                break;
            }
            while (start % 10 != 0 && start <= page) {
                Cal(start, ans, point);
                start++;
            }

            start /= 10;
            page /= 10;

            for (int i = 0; i < 10; i++) {
                ans[i] += (page - start + 1) * point;
            }

            point *= 10;
        }

        for (int i = 0; i < 10; i++) {
            Console.Write(ans[i] + " ");
        }
    }

    static void Cal(int x, int[] ans, int point) {
        while (x > 0) {
            ans[x % 10] += point;
            x /= 10;
        }
    }
}
