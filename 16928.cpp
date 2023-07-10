#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 101;
int N, M;
int ladderAndSnake[MAX];
int minimumMoves[MAX];

int bfs() {
    queue<int> q;
    q.push(1);
    minimumMoves[1] = 0;

    while(!q.empty()) {
        int current = q.front();
        q.pop();

        for(int dice = 1; dice <= 6; dice++) {
            int next = current + dice;
            if(next > 100) break;

            if(ladderAndSnake[next]) {
                next = ladderAndSnake[next];
            }

            if(minimumMoves[next] == -1) {
                minimumMoves[next] = minimumMoves[current] + 1;
                q.push(next);
            }
        }
    }
    return minimumMoves[100];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    fill(minimumMoves, minimumMoves + MAX, -1);

    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        ladderAndSnake[x] = y;
    }

    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        ladderAndSnake[u] = v;
    }

    cout << bfs() << "\n";

    return 0;
}
