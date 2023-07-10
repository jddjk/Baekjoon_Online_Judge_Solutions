#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[101];
bool visited[101] = {false,};
int virusCount = 0;

void dfs(int node) {
    visited[node] = true;
    virusCount++;

    for (int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i];
        if (!visited[next]) {
            dfs(next);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1);

    cout << virusCount - 1;

    return 0;
}
