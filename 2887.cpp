#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Planet {
    int x, y, z, idx;
};

struct Edge {
    int dist, u, v;
};

vector<int> parent;

bool compareX(Planet a, Planet b) { return a.x < b.x; }
bool compareY(Planet a, Planet b) { return a.y < b.y; }
bool compareZ(Planet a, Planet b) { return a.z < b.z; }
bool compareEdge(Edge a, Edge b) { return a.dist < b.dist; }

int find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void unionSet(int u, int v) {
    u = find(u); v = find(v);
    if (u != v) parent[u] = v;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    vector<Planet> planets(N);
    vector<Edge> edges;
    parent = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> planets[i].x >> planets[i].y >> planets[i].z;
        planets[i].idx = i;
    }
    sort(planets.begin(), planets.end(), compareX);
    for (int i = 0; i < N - 1; i++) {
        edges.push_back({abs(planets[i].x - planets[i + 1].x), planets[i].idx, planets[i + 1].idx});
    }
    sort(planets.begin(), planets.end(), compareY);
    for (int i = 0; i < N - 1; i++) {
        edges.push_back({abs(planets[i].y - planets[i + 1].y), planets[i].idx, planets[i + 1].idx});
    }
    sort(planets.begin(), planets.end(), compareZ);
    for (int i = 0; i < N - 1; i++) {
        edges.push_back({abs(planets[i].z - planets[i + 1].z), planets[i].idx, planets[i + 1].idx});
    }
    sort(edges.begin(), edges.end(), compareEdge);
    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }
    long long answer = 0;
    for (Edge e : edges) {
        if (find(e.u) != find(e.v)) {
            unionSet(e.u, e.v);
            answer += e.dist;
        }
    }
    cout << answer;
    return 0;
}
