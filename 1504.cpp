#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 801
#define INF 1000000000
using namespace std;

vector<pair<int,int>> graph[MAX];
int dist[MAX];
bool visited[MAX];
int N, E;

void dijkstra(int start) {
    for(int i = 1; i <= N; i++) {
        dist[i] = INF;
        visited[i] = false;
    }
        
    dist[start] = 0;
    
    for(int i = 0; i < N; i++) {
        int minDist = INF;
        int current;
        
        for(int j = 1; j <= N; j++) {
            if(!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                current = j;
            }
        }
        
        if(minDist == INF) 
            break;
        
        visited[current] = true;
        
        for(auto & p : graph[current]) {
            int neighbor = p.second;
            int nextCost = minDist + p.first;
            
            if(dist[neighbor] > nextCost) {
                dist[neighbor] = nextCost;
            }
        }
    }
}

int main() {
    cin >> N >> E;
    
    for(int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }
    
    int v1, v2;
    cin >> v1 >> v2;
    
    int result1 = 0;
    dijkstra(1);
    if(dist[v1] == INF) {
        cout << -1 << "\n";
        return 0;
    }
    result1 += dist[v1];
    dijkstra(v1);
    if(dist[v2] == INF) {
        cout << -1 << "\n";
        return 0;
    }
    result1 += dist[v2];
    dijkstra(v2);
    if(dist[N] == INF) {
        cout << -1 << "\n";
        return 0;
    }
    result1 += dist[N];
    
    int result2 = 0;
    dijkstra(1);
    if(dist[v2] == INF) {
        cout << -1 << "\n";
        return 0;
    }
    result2 += dist[v2];
    dijkstra(v2);
    if(dist[v1] == INF) {
        cout << -1 << "\n";
        return 0;
    }
    result2 += dist[v1];
    dijkstra(v1);
    if(dist[N] == INF) {
        cout << -1 << "\n";
        return 0;
    }
    result2 += dist[N];
    
    cout << min(result1, result2) << "\n";
    
    return 0;
}
