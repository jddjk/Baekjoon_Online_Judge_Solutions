#include <cstdio>
#include <vector>
#define INF 1e18
using namespace std;

struct Edge {
    int from;
    int to;
    int cost;
};

int n, m;
long long dist[501];
vector<Edge> edges;

bool bellmanFord() {
    dist[1] = 0;
    for (int i = 1; i <= n; i++) {
        for (auto &edge : edges) {
            int from = edge.from;
            int to = edge.to;
            int cost = edge.cost;
            if (dist[from] != INF && dist[to] > dist[from] + cost) {
                dist[to] = dist[from] + cost;
                if (i == n) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        edges.push_back({a, b, c});
    }
    
    if (bellmanFord()) {
        printf("-1\n");
    } else {
        for (int i = 2; i <= n; i++) {
            if (dist[i] == INF) {
                printf("-1\n");
            } else {
                printf("%lld\n", dist[i]);
            }
        }
    }

    return 0;
}
