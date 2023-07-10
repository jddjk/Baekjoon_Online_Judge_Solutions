#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

int t, n;
pair<int, int> loc[102];
vector<int> adj[102];
bool visited[102];

bool reachable(int from, int to) {
    return abs(loc[from].first - loc[to].first) + abs(loc[from].second - loc[to].second) <= 1000;
}

void dfs(int curr) {
    visited[curr] = true;
    for (int next: adj[curr]) {
        if (!visited[next]) dfs(next);
    }
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n + 2; i++) {
            cin >> loc[i].first >> loc[i].second;
            adj[i].clear();
        }

        for (int i = 0; i < n + 2; i++) {
            for (int j = i + 1; j < n + 2; j++) {
                if (reachable(i, j)) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        memset(visited, false, sizeof(visited));
        dfs(0);

        cout << (visited[n + 1] ? "happy" : "sad") << '\n';
    }
    return 0;
}
