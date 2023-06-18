#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, par[51];
char maps[51][51];
priority_queue<pair<int, int>> pq, trash;
int answer[51];

int find(int x) {
    if(x == par[x]) return x;
    par[x] = find(par[x]);
    return par[x];
}

void union_set(int x, int y) {
    x = find(x);
    y = find(y);
    par[y] = x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> maps[i][j];
            if(maps[i][j] == 'Y' && i < j) {
                pq.push({-i, -j});
            }
        }
    }

    if(pq.size() < m) {
        cout << -1 << "\n";
        return 0;
    }

    for(int i = 0; i < n; i++) par[i] = i;

    int cnt = 0;
    while(!pq.empty()) {
        int x = -pq.top().first, y = -pq.top().second; pq.pop();
        if(find(x) != find(y)) {
            union_set(x, y);
            answer[x] += 1;
            answer[y] += 1;
            cnt++;
        } else {
            trash.push({-x, -y});
        }
    }

    if(cnt != n - 1) {
        cout << -1 << "\n";
        return 0;
    }

    for(int i = 0; i < m - cnt; i++) {
        int x = -trash.top().first, y = -trash.top().second; trash.pop();
        answer[x] += 1;
        answer[y] += 1;
    }

    for(int i = 0; i < n; i++) cout << answer[i] << " ";

    return 0;
}
