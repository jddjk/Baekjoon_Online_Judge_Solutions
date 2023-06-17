import java.util.*;
import java.io.*;

public class Main {
    static int[] delay;
    static ArrayList<Integer>[] order;
    static int[] result;
    static int[] indegree;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int K = Integer.parseInt(st.nextToken());

            delay = new int[N + 1];
            result = new int[N + 1];
            indegree = new int[N + 1];
            order = new ArrayList[N + 1];
            for (int j = 1; j <= N; j++) {
                order[j] = new ArrayList<>();
            }

            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= N; j++) {
                delay[j] = Integer.parseInt(st.nextToken());
            }

            for (int j = 0; j < K; j++) {
                st = new StringTokenizer(br.readLine());
                int X = Integer.parseInt(st.nextToken());
                int Y = Integer.parseInt(st.nextToken());
                order[X].add(Y);
                indegree[Y]++;
            }

            int W = Integer.parseInt(br.readLine());

            topologicalSort(N);

            System.out.println(result[W]);
        }
    }

    static void topologicalSort(int N) {
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 1; i <= N; i++) {
            if (indegree[i] == 0) {
                queue.add(i);
                result[i] = delay[i];
            }
        }
        while (!queue.isEmpty()) {
            int current = queue.poll();
            for (int next : order[current]) {
                result[next] = Math.max(result[next], result[current] + delay[next]);
                indegree[next]--;
                if (indegree[next] == 0) {
                    queue.add(next);
                }
            }
        }
    }
}
