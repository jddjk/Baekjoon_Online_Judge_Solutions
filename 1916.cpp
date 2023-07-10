#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;

int N, M;
vector<pair<int, int>> graph[1001];
int d[1001];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    d[start] = 0;
    while (!pq.empty()) {
        int dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (d[now] < dist) continue;
        for (int i = 0; i < graph[now].size(); i++) {
            int cost = dist + graph[now][i].second;
            if (cost < d[graph[now][i].first]) {
                d[graph[now][i].first] = cost;
                pq.push({cost, graph[now][i].first});
            }
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i <= N; i++) d[i] = INF;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    int start, end;
    cin >> start >> end;
    dijkstra(start);
    cout << d[end] << '\n';
    return 0;
}
