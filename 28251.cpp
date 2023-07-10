#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 2e5+5;
int n, q, sz[MAXN], parent[MAXN];
ll dp[MAXN], total[MAXN], totalSquare[MAXN];
multiset<int> ms[MAXN];
vector<pair<int, int>> edges;

int find(int a){
    return parent[a] = (parent[a] == a ? a : find(parent[a]));
}

void merge(int a, int b){
    a = find(a), b = find(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
    total[a] += total[b];
    totalSquare[a] += totalSquare[b];
    dp[a] = (total[a] * total[a] - totalSquare[a]) / 2;
    ms[b].clear();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for(int i=1; i<=n; i++){
        sz[i] = 1, parent[i] = i;
        int s;
        cin >> s;
        ms[i].insert(s);
        total[i] = s;
        totalSquare[i] = s * s;
        dp[i] = (total[i] * total[i] - totalSquare[i]) / 2;
    }
    while(q--){
        int a, b;
        cin >> a >> b;
        merge(a, b);
        cout << dp[find(a)] << "\n";
    }
    return 0;
}
