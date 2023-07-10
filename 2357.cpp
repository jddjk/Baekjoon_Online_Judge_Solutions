#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9+10
using namespace std;

vector<int> arr, tree_min, tree_max;

pair<int, int> init(int start, int end, int node) {
    if (start == end)
        return { tree_min[node] = arr[start], tree_max[node] = arr[start] };
    int mid = (start + end) / 2;
    pair<int, int> left = init(start, mid, node * 2);
    pair<int, int> right = init(mid + 1, end, node * 2 + 1);
    return { tree_min[node] = min(left.first, right.first), tree_max[node] = max(left.second, right.second) };
}

pair<int, int> query(int start, int end, int node, int left, int right) {
    if (left > end || right < start) 
        return { INF, 0 };
    if (left <= start && end <= right) 
        return { tree_min[node], tree_max[node] };
    int mid = (start + end) / 2;
    pair<int, int> q1 = query(start, mid, node * 2, left, right);
    pair<int, int> q2 = query(mid + 1, end, node * 2 + 1, left, right);
    return { min(q1.first, q2.first), max(q1.second, q2.second) };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    arr.resize(N + 1);
    tree_min.resize(4 * N);
    tree_max.resize(4 * N);

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    init(1, N, 1);

    while (M--) {
        int a, b;
        cin >> a >> b;
        pair<int, int> result = query(1, N, 1, a, b);
        cout << result.first << ' ' << result.second << "\n";
    }
    
    return 0;
}
