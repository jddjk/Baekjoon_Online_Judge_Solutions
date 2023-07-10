#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;
pair<pii, pii> a[3005];
int par[3005], sz[3005];

ll ccw(pii a, pii b, pii c) {
    ll op = 1LL*a.first*b.second + 1LL*b.first*c.second + 1LL*c.first*a.second;
    op -= (1LL*a.second*b.first + 1LL*b.second*c.first + 1LL*c.second*a.first);
    if(op > 0) return 1;
    else if(op == 0) return 0;
    else return -1;
}

bool isIntersect(int x, int y) {
    pii a1 = a[x].first;
    pii b1 = a[x].second;
    pii a2 = a[y].first;
    pii b2 = a[y].second;
    int f1 = ccw(a1, b1, a2)*ccw(a1, b1, b2);
    int f2 = ccw(a2, b2, a1)*ccw(a2, b2, b1);
    if(f1 <= 0 && f2 <= 0) {
        if(a1 > b1) swap(a1, b1);
        if(a2 > b2) swap(a2, b2);
        if(a1 <= b2 && a2 <= b1) return true;
    }
    return false;
}

int find(int u) {
    if(u == par[u]) return u;
    return par[u] = find(par[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if(u != v) {
        par[u] = v;
        sz[v] += sz[u];
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d%d%d%d", &a[i].first.first, &a[i].first.second, &a[i].second.first, &a[i].second.second);
        par[i] = i;
        sz[i] = 1;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            if(isIntersect(i, j)) {
                merge(i, j);
            }
        }
    }
    int group = 0, max_sz = 0;
    for(int i = 1; i <= n; i++) {
        if(i == par[i]) {
            group++;
            max_sz = max(max_sz, sz[i]);
        }
    }
    printf("%d\n%d\n", group, max_sz);
    return 0;
}
