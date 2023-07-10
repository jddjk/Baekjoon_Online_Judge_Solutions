#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 1000001

int F, S, G, U, D;
vector<bool> visited(MAX, false);
vector<int> dist(MAX, 0);

void bfs() {
    queue<int> q;
    q.push(S);
    visited[S] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == G) {
            return;
        }

        int next = curr + U;
        if (next <= F && !visited[next]) {
            visited[next] = true;
            dist[next] = dist[curr] + 1;
            q.push(next);
        }

        next = curr - D;
        if (next >= 1 && !visited[next]) {
            visited[next] = true;
            dist[next] = dist[curr] + 1;
            q.push(next);
        }
    }
}

int main() {
    cin >> F >> S >> G >> U >> D;

    bfs();

    if (visited[G]) {
        cout << dist[G];
    } else {
        cout << "use the stairs";
    }

    return 0;
}
