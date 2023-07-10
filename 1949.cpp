#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX=10001;
int people[MAX],DP[MAX][2];
vector<int> adj[MAX];
bool visited[MAX];
void dfs(int now){
    visited[now]=true;
    DP[now][0]=0;
    DP[now][1]=people[now];
    for(int i=0;i<adj[now].size();i++){
        int next=adj[now][i];
        if(visited[next]) continue;
        dfs(next);
        DP[now][0]+=max(DP[next][0],DP[next][1]);
        DP[now][1]+=DP[next][0];
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>>N;
    for(int i=1;i<=N;i++) cin>>people[i];
    for(int i=0;i<N-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    cout<<max(DP[1][0],DP[1][1])<<'\n';
    return 0;
}
