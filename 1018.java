import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        sc.nextLine();

        char[][] board = new char[n][m];
        for (int i = 0; i < n; i++) {
            String line = sc.nextLine();
            for (int j = 0; j < m; j++) {
                board[i][j] = line.charAt(j);
            }
        }

        int minCount = Integer.MAX_VALUE;
        for (int i = 0; i <= n - 8; i++) {
            for (int j = 0; j <= m - 8; j++) {
                int count1 = countPaint(board, i, j, 'W');
                int count2 = countPaint(board, i, j, 'B');
                int minCountForSubBoard = Math.min(count1, count2);
                minCount = Math.min(minCount, minCountForSubBoard);
            }
        }

        System.out.println(minCount);
    }

    private static int countPaint(char[][] board, int startRow, int startCol, char startColor) {
        int count = 0;
        char currentColor = startColor;

        for (int i = startRow; i < startRow + 8; i++) {
            for (int j = startCol; j < startCol + 8; j++) {
                if (board[i][j] != currentColor) {
                    count++;
                }
                currentColor = flipColor(currentColor);
            }
            currentColor = flipColor(currentColor);
        }

        return count;
    }

    private static char flipColor(char color) {
        if (color == 'W') {
            return 'B';
        } else {
            return 'W';
        }
    }
}
