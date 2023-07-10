#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int pd;
        cin >> pd;
        vector<int> seq(pd);
        for (int j = 0; j < pd; j++) {
            cin >> seq[j];
        }
        for (int j = 1; j < pd; j++) {
            adj[seq[j - 1]].push_back(seq[j]);
            indegree[seq[j]]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    vector<int> result;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        result.push_back(curr);
        for (int next : adj[curr]) {
            if (--indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    if (result.size() == n) {
        for (int i : result) cout << i << '\n';
    } else {
        cout << 0;
    }

    return 0;
}
