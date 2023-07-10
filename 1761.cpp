#include <bits/stdc++.h>
using namespace std;
#define MAX 40001
#define LOG 17


int N, M;
vector<pair<int, int>> graph[MAX];
int parent[MAX][LOG];
int depth[MAX];
int dist[MAX];

void dfs(int node, int d, int distance) {
    depth[node] = d;
    dist[node] = distance;
    for (auto next : graph[node]) {
        if (depth[next.first] == -1) {
            parent[next.first][0] = node;
            dfs(next.first, d + 1, distance + next.second);
        }
    }
}

void f() {
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= N; i++) {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    for (int i = LOG - 1; i >= 0; i--) {
        if (depth[a] - (1 << i) >= depth[b])
            a = parent[a][i];
    }
    if (a == b) return a;
    for (int i = LOG - 1; i >= 0; i--) {
        if (parent[a][i] != parent[b][i]) {
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    return parent[a][0];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }
    memset(parent, 0, sizeof(parent));
    memset(depth, -1, sizeof(depth));
    dfs(1, 0, 0);
    f();

    cin >> M;
    while (M--) {
        int a, b;
        cin >> a >> b;
        int common = lca(a, b);
        cout << dist[a] + dist[b] - 2 * dist[common] << '\n';
    }
    return 0;
}
