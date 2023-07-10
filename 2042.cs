using System;
using System.Linq;

public class SegmentTree {
    private long[] arr;
    private long[] tree;

    public SegmentTree(int N, long[] arr) {
        this.arr = arr;
        int height = (int)Math.Ceiling(Math.Log(N) / Math.Log(2));
        int treeSize = (int)Math.Pow(2, height + 1);
        tree = new long[treeSize];
        Init(0, N - 1, 1);
    }

    private long Init(int start, int end, int node) {
        if (start == end) return tree[node] = arr[start];
        int mid = (start + end) / 2;
        return tree[node] = Init(start, mid, node * 2) + Init(mid + 1, end, node * 2 + 1);
    }

    public void Update(int start, int end, int node, int idx, long diff) {
        if (idx < start || idx > end) return;
        tree[node] += diff;
        if (start != end) {
            int mid = (start + end) / 2;
            Update(start, mid, node * 2, idx, diff);
            Update(mid + 1, end, node * 2 + 1, idx, diff);
        }
    }

    public long Sum(int start, int end, int node, int left, int right) {
        if (left > end || right < start) return 0;
        if (left <= start && end <= right) return tree[node];
        int mid = (start + end) / 2;
        return Sum(start, mid, node * 2, left, right) + Sum(mid + 1, end, node * 2 + 1, left, right);
    }
}

public class MainApp {
    static void Main(string[] args) {
        int[] NMK = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int N = NMK[0];
        int M = NMK[1];
        int K = NMK[2];
        long[] arr = new long[N];
        for (int i = 0; i < N; i++) {
            arr[i] = long.Parse(Console.ReadLine());
        }
        SegmentTree segmentTree = new SegmentTree(N, arr);
        for (int i = 0; i < M + K; i++) {
            long[] abc = Console.ReadLine().Split().Select(long.Parse).ToArray();
            int a = (int)abc[0];
            int b = (int)abc[1];
            long c = abc[2];
            if (a == 1) {
                long diff = c - arr[b - 1];
                arr[b - 1] = c;
                segmentTree.Update(0, N - 1, 1, b - 1, diff);
            } else {
                Console.WriteLine(segmentTree.Sum(0, N - 1, 1, b - 1, (int)c - 1));
            }
        }
    }
}
