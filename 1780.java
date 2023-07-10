import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class Main {
    static int[][] paper;
    static int[] count = new int[3];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        paper = new int[N][N];

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                paper[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        cutPaper(0, 0, N);

        for (int i = 0; i < 3; i++) {
            System.out.println(count[i]);
        }
    }
    public static void cutPaper(int row, int col, int size) {
        if (check(row, col, size)) {
            count[paper[row][col] + 1]++;
        } else {
            int newSize = size / 3;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cutPaper(row + newSize * i, col + newSize * j, newSize);
                }
            }
        }
    }

    public static boolean check(int row, int col, int size) {
        int num = paper[row][col];
        for (int i = row; i < row + size; i++) {
            for (int j = col; j < col + size; j++) {
                if (paper[i][j] != num) {
                    return false;
                }
            }
        }
        return true;
    }
}
