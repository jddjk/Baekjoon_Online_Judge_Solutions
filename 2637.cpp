#include <iostream>
#include <vector>
#include <queue>
using namespace std;int main(){int N,M;cin>>N>>M;vector<vector<pair<int,int>>>g(N+1);vector<int>p(N+1,0),a(N+1,0),b(N+1,0);for(int i=0;i<M;i++){int X,Y,K;cin>>X>>Y>>K;g[X].push_back({Y,K});b[X]=1;p[Y]++;}queue<int>q;q.push(N);a[N]=1;while(!q.empty()){int c=q.front();q.pop();for(auto&next:g[c]){a[next.first]+=a[c]*next.second;if(--p[next.first]==0)q.push(next.first);}}for(int i=1;i<=N;i++){if(!b[i]){cout<<i<<' '<<a[i]<<endl;}}}
