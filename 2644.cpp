#include <iostream>
#include <vector>
#include <queue>
#define MAX 101

using namespace std;

vector<int> graph[MAX];
int dist[MAX];
bool visited[MAX] = { false, };

void bfs(int start) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (int i = 0; i < graph[current].size(); i++) {
            int next = graph[current][i];
            if (!visited[next]) {
                visited[next] = true;
                dist[next] = dist[current] + 1;
                q.push(next);
            }
        }
    }
}

int main() {
    int n, m;
    int person1, person2;
    cin >> n >> person1 >> person2 >> m;

    for (int i = 0; i < m; i++) {
        int parent, child;
        cin >> parent >> child;
        graph[parent].push_back(child);
        graph[child].push_back(parent);
    }

    bfs(person1);

    if (visited[person2]) {
        cout << dist[person2];
    } else {
        cout << "-1";
    }

    return 0;
}
