#include <iostream>
#include <vector>
using namespace std;

vector<int> parent(201);

int find(int x) {
    if (parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}

void union_find(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) parent[y] = x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) parent[i] = i;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int temp;
            cin >> temp;
            if (temp) union_find(i, j);
        }
    }

    vector<int> plan(M);
    for (int i = 0; i < M; i++) {
        cin >> plan[i];
    }

    for (int i = 0; i < M - 1; i++) {
        if (find(plan[i]) != find(plan[i + 1])) {
            cout << "NO" << '\n';
            return 0;
        }
    }

    cout << "YES" << '\n';
    return 0;
}
