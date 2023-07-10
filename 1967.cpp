#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
 
vector<pair<int,int>> v[10001];
int visit[10001];
int dist[10001];
int maxN,maxDist;
 
void dfs(int node, int d){
    if(visit[node]) return;
    visit[node]=1;
    dist[node] = d;
    if(maxDist < dist[node]){
        maxDist = dist[node];
        maxN = node;
    }
    for(int i=0; i<v[node].size(); i++){
        dfs(v[node][i].first, d + v[node][i].second);
    }
}
 
int main(void){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N; cin>>N;
    for(int i=1; i<N; i++){
        int a,b,c; cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    dfs(1,0);
    memset(visit,0,sizeof(visit));
    memset(dist,0,sizeof(dist));
    maxDist = 0;
    dfs(maxN, 0);
    cout<<maxDist;
    return 0;
}
