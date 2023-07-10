#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100000;
bool visited[MAX + 1];

int bfs(int start, int target) {
    queue<pair<int, int>> q;
    q.push(make_pair(start, 0));
    visited[start] = true;
    
    while (!q.empty()) {
        int curPos = q.front().first;
        int time = q.front().second;
        q.pop();
        
        if (curPos == target) {
            return time;
        }
        
        if (curPos - 1 >= 0 && !visited[curPos - 1]) {
            q.push(make_pair(curPos - 1, time + 1));
            visited[curPos - 1] = true;
        }
        
        if (curPos + 1 <= MAX && !visited[curPos + 1]) {
            q.push(make_pair(curPos + 1, time + 1));
            visited[curPos + 1] = true;
        }
        
        if (curPos * 2 <= MAX && !visited[curPos * 2]) {
            q.push(make_pair(curPos * 2, time + 1));
            visited[curPos * 2] = true;
        }
    }
    
    return 0;
}

int main() {
    int N, K;
    cin >> N >> K;
    
    int result = bfs(N, K);
    cout << result << endl;
    
    return 0;
}
