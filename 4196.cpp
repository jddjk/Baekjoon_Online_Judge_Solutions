#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;

int n, m, sccnum, disnum;
vector<int> adj[100005];
vector<int> discovered(100005, -1), sccid(100005, -1), indegree(100005, 0);
stack<int> st;

int scc(int here) {
    int ret = discovered[here] = disnum++;
    st.push(here);

    for (int there : adj[here]) {
        if (discovered[there] == -1)
            ret = min(ret, scc(there));
        else if (sccid[there] == -1)
            ret = min(ret, discovered[there]);
    }

    if (ret == discovered[here]) {
        while (true) {
            int x = st.top(); st.pop();
            sccid[x] = sccnum;
            if (here == x) break;
        }
        ++sccnum;
    }

    return ret;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
        discovered[i] = -1;
        sccid[i] = -1;
        indegree[i] = 0;
    }
    disnum = sccnum = 0;
    while (!st.empty()) st.pop();

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        if (discovered[i] == -1)
            scc(i);
    }

    for (int i = 1; i <= n; i++) {
        for (int j : adj[i]) {
            if (sccid[i] != sccid[j]) {
                indegree[sccid[j]]++;
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < sccnum; i++) {
        if (indegree[i] == 0)
            answer++;
    }
    cout << answer << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
