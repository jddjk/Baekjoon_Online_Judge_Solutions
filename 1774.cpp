#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define MAX 1001
using namespace std;

int n, m;
pair<double, double> arr[MAX];
int parent[MAX];
vector<pair<double, pair<int, int>>> edges;

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

double getDistance(pair<double, double> a, pair<double, double> b) {
    double x = a.first - b.first;
    double y = a.second - b.second;
    return sqrt(pow(x, 2) + pow(y, 2));
}

int main() {
    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        parent[i] = i;
    }

    for(int i=1; i<=n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            edges.push_back({getDistance(arr[i], arr[j]), {i, j}});
        }
    }

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        unionParent(a, b);
    }

    sort(edges.begin(), edges.end());

    double result = 0;

    for(int i=0; i<edges.size(); i++) {
        double cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;

        if(findParent(a) != findParent(b)) {
            unionParent(a, b);
            result += cost;
        }
    }

    printf("%.2lf\n", result);
    return 0;
}
