#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 10000;
bool visited[MAX];
string path[MAX];

void bfs(int start, int end) {
    memset(visited, false, sizeof(visited));
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        int next = (2 * now) % 10000;
        if (!visited[next]) {
            visited[next] = true;
            path[next] = path[now] + 'D';
            if (next == end) {
                cout << path[next] << "\n";
                return;
            }
            q.push(next);
        }
        next = (now - 1) < 0 ? 9999 : now - 1;
        if (!visited[next]) {
            visited[next] = true;
            path[next] = path[now] + 'S';
            if (next == end) {
                cout << path[next] << "\n";
                return;
            }
            q.push(next);
        }
        next = (now % 1000) * 10 + now / 1000;
        if (!visited[next]) {
            visited[next] = true;
            path[next] = path[now] + 'L';
            if (next == end) {
                cout << path[next] << "\n";
                return;
            }
            q.push(next);
        }
        next = (now % 10) * 1000 + now / 10;
        if (!visited[next]) {
            visited[next] = true;
            path[next] = path[now] + 'R';
            if (next == end) {
                cout << path[next] << "\n";
                return;
            }
            q.push(next);
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int A, B;
        cin >> A >> B;
        bfs(A, B);
        for (int i = 0; i < MAX; i++) {
            path[i].clear();
        }
    }
    return 0;
}
