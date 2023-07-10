#include <iostream>
#include <queue>
#include <vector>
#define MAX 21
#define INF 987654321

using namespace std;

struct info { int x, y, dist; };
struct compare {
    bool operator()(info a, info b) {
        if (a.dist < b.dist) return false;
        else if (a.dist == b.dist) {
            if (a.x < b.x) return false;
            else if (a.x == b.x) {
                if (a.y < b.y) return false;
            }
        }
        return true;
    }
};

int N;
int space[MAX][MAX];
int sharkX, sharkY;
int sharkSize = 2;
int eatCount = 0;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
int minDist = INF;
int minX = INF;
int minY = INF;
int result = 0;

void bfs() {
    priority_queue<info, vector<info>, compare> pq;
    int visited[MAX][MAX] = { 0, };
    pq.push({ sharkX, sharkY, 0 });
    visited[sharkX][sharkY] = true;

    while (!pq.empty()) {
        int x = pq.top().x;
        int y = pq.top().y;
        int dist = pq.top().dist;
        pq.pop();

        if (space[x][y] >= 1 && space[x][y] < sharkSize) {
            if (dist < minDist) {
                minDist = dist;
                minX = x;
                minY = y;
            }
            else if (dist == minDist) {
                if (x < minX) {
                    minX = x;
                    minY = y;
                }
                else if (x == minX) {
                    if (y < minY) {
                        minY = y;
                    }
                }
            }
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

            if (!visited[nx][ny] && space[nx][ny] <= sharkSize) {
                pq.push({ nx, ny, dist + 1 });
                visited[nx][ny] = true;
            }
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> space[i][j];
            if (space[i][j] == 9) {
                sharkX = i;
                sharkY = j;
                space[i][j] = 0;
            }
        }
    }

    while (1) {
        minDist = INF;
        minX = INF;
        minY = INF;
        bfs();
        if (minX != INF) {
            eatCount++;
            if (eatCount == sharkSize) {
                sharkSize++;
                eatCount = 0;
            }
            space[minX][minY] = 0;
            sharkX = minX;
            sharkY = minY;
            result += minDist;
        }
        else break;
    }

    cout << result << endl;

    return 0;
}
