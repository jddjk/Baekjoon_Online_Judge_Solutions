#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 25

using namespace std;

int N;
int map[MAX][MAX];
bool visited[MAX][MAX] = {false,};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int bfs(int x, int y) {
    int count = 1;
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()) {
        int currentX = q.front().first;
        int currentY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = currentX + dx[i];
            int nextY = currentY + dy[i];

            if (0 <= nextX && nextX < N && 0 <= nextY && nextY < N) {
                if (map[nextX][nextY] == 1 && !visited[nextX][nextY]) {
                    visited[nextX][nextY] = true;
                    q.push({nextX, nextY});
                    count++;
                }
            }
        }
    }
    return count;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    vector<int> result;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1 && !visited[i][j]) {
                result.push_back(bfs(i, j));
            }
        }
    }

    sort(result.begin(), result.end());
    cout << result.size() << '\n';
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << '\n';
    }

    return 0;
}
