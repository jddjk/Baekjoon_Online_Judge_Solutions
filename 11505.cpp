#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

typedef long long ll;

vector<ll> arr, tree;

ll init(int start, int end, int node) {
    if (start == end)
        return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = (init(start, mid, node * 2) * init(mid + 1, end, node * 2 + 1)) % MOD;
}

ll update(int start, int end, int node, int index, ll num) {
    if (index < start || index > end) 
        return tree[node];
    if (start == end) 
        return tree[node] = num;
    int mid = (start + end) / 2;
    return tree[node] = (update(start, mid, node * 2, index, num) * update(mid + 1, end, node * 2 + 1, index, num)) % MOD;
}

ll query(int start, int end, int node, int left, int right) {
    if (left > end || right < start) 
        return 1;
    if (left <= start && end <= right) 
        return tree[node];
    int mid = (start + end) / 2;
    return (query(start, mid, node * 2, left, right) * query(mid + 1, end, node * 2 + 1, left, right)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    arr.resize(N + 1);
    tree.resize(4 * N);

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    init(1, N, 1);

    M += K;

    while (M--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            arr[b] = c;
            update(1, N, 1, b, c);
        }
        else
            cout << query(1, N, 1, b, c) % MOD << "\n";
    }
    
    return 0;
}
