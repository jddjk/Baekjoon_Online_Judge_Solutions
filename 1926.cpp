#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int dx[4]={-1,0,1,0}, dy[4]={0,1,0,-1};
int map[500][500], visited[500][500];

int DFS(int x, int y) {
    visited[x][y] = 1;
    int area = 1;

    for(int i=0; i<4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if(next_x >= 0 && next_x < n && next_y >= 0 && next_y < m) {
            if(map[next_x][next_y] == 1 && visited[next_x][next_y] == 0) {
                area += DFS(next_x, next_y);
            }
        }
    }

    return area;
}

int main() {
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> map[i][j];
        }
    }

    int cnt = 0, max_area = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(map[i][j] == 1 && visited[i][j] == 0) {
                max_area = max(max_area, DFS(i, j));
                cnt++;
            }
        }
    }

    cout << cnt << "\n" << max_area;

    return 0;
}
