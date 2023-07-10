#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<vector<char>> maze(200, vector<char>(200, '#'));
    int x = 100, y = 100, d = 0;
    maze[x][y] = '.';

    for(char c : s) {
        if(c == 'F') {
            x += dx[d];
            y += dy[d];
        } else if(c == 'L') {
            d = (d + 1) % 4;
        } else if(c == 'R') {
            d = (d + 3) % 4;
        }
        maze[x][y] = '.';
    }

    int min_x = 200, min_y = 200, max_x = 0, max_y = 0;
    for(int i = 0; i < 200; i++) {
        for(int j = 0; j < 200; j++) {
            if(maze[i][j] == '.') {
                min_x = min(min_x, i);
                min_y = min(min_y, j);
                max_x = max(max_x, i);
                max_y = max(max_y, j);
            }
        }
    }

    for(int i = min_x; i <= max_x; i++) {
        for(int j = min_y; j <= max_y; j++) {
            cout << maze[i][j];
        }
        cout << '\n';
    }

    return 0;
}
