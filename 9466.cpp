#include<bits/stdc++.h>
using namespace std;

int T, n;
int arr[100001], visited[100001], finished[100001];
int cnt;

void dfs(int now) {
    visited[now] = true;
    int next = arr[now];

    if (visited[next]) {
        if (!finished[next]) {
            for (int i=next; i!=now; i=arr[i])
                cnt++;
            cnt++; 
        }
    } else
        dfs(next);

    finished[now] = true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while (T--) {
        memset(arr, 0, sizeof(arr));
        memset(visited, false, sizeof(visited));
        memset(finished, false, sizeof(finished));
        cnt = 0;

        cin >> n;
        for (int i=1; i<=n; i++)
            cin >> arr[i];

        for (int i=1; i<=n; i++)
            if (!visited[i])
                dfs(i);

        cout << n-cnt << '\n';
    }
    return 0;
}
