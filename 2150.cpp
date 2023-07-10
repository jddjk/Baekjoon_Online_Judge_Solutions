#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int V, E, order;
vector<int> adj[10001];
int visited_order[10001];
bool is_scc[10001];
vector<vector<int>> sccs;
stack<int> st;

int FindSCC(int now_idx) {
    int min_order = visited_order[now_idx] = ++order;
    int next_idx;
    st.push(now_idx);

    for(int i=0; i<adj[now_idx].size(); ++i) {
        next_idx = adj[now_idx][i];
        if(visited_order[next_idx] == 0)
            min_order = min(min_order, FindSCC(next_idx));
        else if(!is_scc[next_idx])
            min_order = min(min_order, visited_order[next_idx]);
    }

    if(min_order == visited_order[now_idx]) {
        vector<int> new_scc;
        while(1) {
            int temp = st.top();
            st.pop();
            is_scc[temp] = true;
            new_scc.push_back(temp);
            if(temp == now_idx)
                break;
        }
        sort(new_scc.begin(), new_scc.end());
        sccs.push_back(new_scc);
    }

    return min_order;
}

int main() {
    cin >> V >> E;

    for(int i=0; i<E; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for(int i=1; i<=V; ++i)
        if(visited_order[i] == 0)
            FindSCC(i);

    cout << sccs.size() << "\n";
    sort(sccs.begin(), sccs.end());

    for(int i=0; i<sccs.size(); ++i) {
        for(int j=0; j<sccs[i].size(); ++j)
            cout << sccs[i][j] << " ";
        cout << "-1\n";
    }

    return 0;
}
