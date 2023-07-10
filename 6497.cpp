#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 200001
using namespace std;

int m, n;
int parent[MAX];
vector<pair<int, pair<int, int>>> edges;

int findParent(int x) {
    if(parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

int main() {
    while(1) {
        cin >> m >> n;
        if(m == 0 && n == 0) break;

        for(int i=0; i<m; i++) {
            parent[i] = i;
        }

        int totalCost = 0;
        edges.clear();
        for(int i=0; i<n; i++) {
            int a, b, cost;
            cin >> a >> b >> cost;
            edges.push_back({cost, {a, b}});
            totalCost += cost;
        }

        sort(edges.begin(), edges.end());

        int minCost = 0;

        for(int i=0; i<edges.size(); i++) {
            int cost = edges[i].first;
            int a = edges[i].second.first;
            int b = edges[i].second.second;

            if(findParent(a) != findParent(b)) {
                unionParent(a, b);
                minCost += cost;
            }
        }

        cout << totalCost - minCost << '\n';
    }
    return 0;
}
