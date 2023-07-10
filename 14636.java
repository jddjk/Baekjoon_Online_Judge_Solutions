import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    public static ArrayList<Couple> normalize(ArrayList<Couple> v) {
        ArrayList<Couple> ret = new ArrayList<>();
        Collections.sort(v);
        for (int i = 0; i < v.size(); i++) {
            while (ret.size() > 0 && ret.get(ret.size()-1).first <= v.get(i).first &&
                ret.get(ret.size()-1).second <= v.get(i).second) {
                ret.remove(ret.size()-1);
            }
            ret.add(v.get(i));
        }
        return ret;
    }

    public static ArrayList<Couple> rev(ArrayList<Couple> v) {
        Collections.reverse(v);
        for (int i = 0; i < v.size(); i++) {
            v.get(i).first = -v.get(i).first;
            v.get(i).second = -v.get(i).second;
        }
        return v;
    }

    public static long doit(ArrayList<Couple> a, int ai1, int ai2, ArrayList<Couple> b, int bi1, int bi2,
               boolean swapped) {
        if (ai2-ai1 <= 50 || bi2-bi1 <= 50) {
            long ret = 0;
            for (int i = ai1; i < ai2; i++)
            for (int j = bi1; j < bi2; j++) {
                if (swapped) {
                    ret = Math.max(ret, (long)Math.min(0, b.get(j).first-a.get(i).first) *
                                (b.get(j).second-a.get(i).second));
                } else {
                    ret = Math.max(ret, (long)Math.max(0, b.get(j).first-a.get(i).first) *
                                (b.get(j).second-a.get(i).second));
                }
            }
            return ret;
        }

        ArrayList<Couple> b1 = new ArrayList<>(), b2 = new ArrayList<>();
        int i = (ai2+ai1)/2;
        for (int j = bi1; j+1 < bi2; j += 2) {
            long v1 = (long)(b.get(j).first-a.get(i).first) *
                                (b.get(j).second-a.get(i).second);
            long v2 = (long)(b.get(j+1).first-a.get(i).first) *
                                (b.get(j+1).second-a.get(i).second);
            if (v1 < v2) {
                b1.add(b.get(j)); b1.add(b.get(j+1)); b2.add(b.get(j+1));
            } else {
                b1.add(b.get(j)); b2.add(b.get(j)); b2.add(b.get(j+1));
            }
        }
        if ((bi2-bi1)%2 == 1) { b1.add(b.get(bi2-1)); b2.add(b.get(bi2-1)); }

        return Math.max(doit(b1, 0, b1.size(), a, ai1, i, !swapped),
                 doit(b2, 0, b2.size(), a, i, ai2, !swapped));
    }

    public static void main(String[] args) throws Exception {
        int Producers, Consumers;
        st = new StringTokenizer(br.readLine());
        Producers = Integer.parseInt(st.nextToken());
        Consumers = Integer.parseInt(st.nextToken());
        ArrayList<Couple> ProducerVector = new ArrayList<>(), ConsumerVector = new ArrayList<>();
        for (int i = 0; i < Producers; i++) {
            st = new StringTokenizer(br.readLine());
            ProducerVector.add(new Couple(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
        }
        for (int i = 0; i < Consumers; i++) {
            st = new StringTokenizer(br.readLine());
            ConsumerVector.add(new Couple(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
        }

        ProducerVector = rev(normalize(rev(ProducerVector)));
        ConsumerVector = normalize(ConsumerVector);

        bw.write(Long.toString(doit(ProducerVector, 0, ProducerVector.size(), ConsumerVector, 0, ConsumerVector.size(), false)) + "\n");
        bw.flush();
    }
}

class Couple implements Comparable<Couple> {
    public int first;
    public int second;

    public Couple(int first, int second) {
        this.first = first;
        this.second = second;
    }

    @Override
    public int compareTo(Couple o) {
        if (this.first == o.first) {
            return this.second - o.second;
        } else {
            return this.first - o.first;
        }
    }
}
