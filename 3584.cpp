#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;

        vector<int> parent(N + 1, 0);
        vector<bool> check(N + 1, false);

        for (int i = 0; i < N - 1; ++i) {
            int u, v;
            cin >> u >> v;
            parent[v] = u;
        }

        int u, v;
        cin >> u >> v;

        while(u) {
            check[u] = true;
            u = parent[u];
        }

        while(v) {
            if(check[v]) {
                cout << v << '\n';
                break;
            }
            v = parent[v];
        }
    }

    return 0;
}
