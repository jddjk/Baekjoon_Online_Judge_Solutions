#include <iostream>
#include <vector>
#define ll long long

using namespace std;

int N, M;
vector<ll> arr, tree, lazy;

ll init(int node, int start, int end) {
    if(start == end)
        return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

void update_lazy(int node, int start, int end) {
    if(lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];
        if(start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update_range(int node, int start, int end, int left, int right, ll diff) {
    update_lazy(node, start, end);
    if(left > end || right < start)
        return;
    if(left <= start && end <= right) {
        tree[node] += (end - start + 1) * diff;
        if(start != end) {
            lazy[node * 2] += diff;
            lazy[node * 2 + 1] += diff;
        }
        return;
    }
    int mid = (start + end) / 2;
    update_range(node * 2, start, mid, left, right, diff);
    update_range(node * 2 + 1, mid + 1, end, left, right, diff);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll sum(int node, int start, int end, int left, int right) {
    update_lazy(node, start, end);
    if(left > end || right < start)
        return 0;
    if(left <= start && end <= right)
        return tree[node];
    int mid = (start + end) / 2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    arr.resize(N+1);
    tree.resize(4*N);
    lazy.resize(4*N);
    for(int i=1; i<=N; i++)
        cin >> arr[i];
    init(1, 1, N);
    
    cin >> M;
    while(M--) {
        int op;
        cin >> op;
        if(op == 1) {
            int i, j, k;
            cin >> i >> j >> k;
            update_range(1, 1, N, i, j, k);
        } else if(op == 2) {
            int x;
            cin >> x;
            cout << sum(1, 1, N, x, x) << "\n";
        }
    }

    return 0;
}
