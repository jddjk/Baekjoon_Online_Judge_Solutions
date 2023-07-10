#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100000;

int parent[MAX];
vector<pair<int, pair<int, int>>> edges;

int find(int x) {
    if (x == parent[x])
        return x;
    return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y)
        parent[y] = x;
}

bool same(int x, int y) {
    return find(x) == find(y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        edges.push_back({C, {A, B}});
    }

    sort(edges.begin(), edges.end());

    int totalCost = 0, maxCost = 0;
    for (int i = 0; i < edges.size(); i++) {
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;

        if (!same(a, b)) {
            unite(a, b);
            totalCost += cost;
            maxCost = max(maxCost, cost);
        }
    }

    cout << totalCost - maxCost << "\n";

    return 0;
}
