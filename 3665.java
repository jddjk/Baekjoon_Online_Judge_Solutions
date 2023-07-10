import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int t = Integer.parseInt(br.readLine());
        
        while(t-- > 0) {
            int n = Integer.parseInt(br.readLine());

            int[] indegree = new int[n + 1];
            ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
            for(int i = 0; i <= n; i++)
                graph.add(new ArrayList<Integer>());

            int[] team = new int[n + 1];
            String[] line = br.readLine().split(" ");
            for(int i = 1; i <= n; i++) {
                team[i] = Integer.parseInt(line[i - 1]);
            }

            for(int i = 1; i <= n; i++) {
                for(int j = i + 1; j <= n; j++) {
                    graph.get(team[i]).add(team[j]);
                    indegree[team[j]]++;
                }
            }

            int m = Integer.parseInt(br.readLine());
            for(int i = 0; i < m; i++) {
                line = br.readLine().split(" ");
                int a = Integer.parseInt(line[0]);
                int b = Integer.parseInt(line[1]);

                if(graph.get(a).contains(b)) {
                    graph.get(a).remove((Integer) b);
                    graph.get(b).add(a);
                    indegree[a]++;
                    indegree[b]--;
                } else {
                    graph.get(b).remove((Integer) a);
                    graph.get(a).add(b);
                    indegree[b]++;
                    indegree[a]--;
                }
            }

            Queue<Integer> q = new LinkedList<>();
            ArrayList<Integer> result = new ArrayList<>();

            for(int i = 1; i <= n; i++) {
                if(indegree[i] == 0) {
                    q.offer(i);
                }
            }

            while(!q.isEmpty()) {
                if(q.size() > 1) {
                    bw.write("?\n");
                    bw.flush();
                    break;
                }

                int now = q.poll();
                result.add(now);

                for(int next : graph.get(now)) {
                    indegree[next]--;

                    if(indegree[next] == 0) {
                        q.offer(next);
                    }
                }
            }

            if(result.size() == n) {
                for(int i : result) {
                    bw.write(i + " ");
                }
                bw.write("\n");
                bw.flush();
            } else if(q.isEmpty()) {
                bw.write("IMPOSSIBLE\n");
                bw.flush();
            }
        }
        bw.close();
        br.close();
    }
}
