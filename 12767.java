import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static boolean pushFunction(List<Integer> a, List<Integer> b) {
        if (a.size() != b.size()) return false;
        if (a.size() <= 1) return true;

        List<Integer> al = new ArrayList<>(), ar = new ArrayList<>(), bl = new ArrayList<>(), br = new ArrayList<>();
        for (int i = 1; i < a.size(); i++) {
            (a.get(i) < a.get(0) ? al : ar).add(a.get(i));
            (b.get(i) < b.get(0) ? bl : br).add(b.get(i));
        }
        return pushFunction(al, bl) && pushFunction(ar, br);
    }

    public static void main(String[] args) throws Exception {
        String line;
        while ((line = br.readLine()) != null) {
            StringTokenizer st = new StringTokenizer(line);
            int prototypes = Integer.parseInt(st.nextToken()), layers = Integer.parseInt(st.nextToken());

            List<List<Integer>> tree = new ArrayList<>();
            int ret = 0;
            for (int i = 0; i < prototypes; i++) {
                tree.add(new ArrayList<>());
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < layers; j++)
                    tree.get(i).add(Integer.parseInt(st.nextToken()));

                int j;
                for (j = 0; j < i; j++)
                    if (pushFunction(tree.get(i), tree.get(j)))
                        break;

                if (j == i)
                    ret++;
            }
            System.out.println(ret);
        }
    }
}
