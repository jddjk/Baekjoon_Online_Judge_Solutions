#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dr[5] = { -1, 0, 0, 0, 1 };
int dc[5] = { 0, -1, 0, 1, 0 };

void flip(vector<string>& bulbs, int r, int c) {
    for (int d = 0; d < 5; d++) {
        int nr = r + dr[d], nc = c + dc[d];
        if (nr < 0 || nc < 0 || nr >= 10 || nc >= 10) continue;
        bulbs[nr][nc] = bulbs[nr][nc] == '#' ? 'O' : '#';
    }
}

bool allOff(const vector<string>& bulbs) {
    for (const auto& row : bulbs) {
        for (char bulb : row) {
            if (bulb == 'O') return false;
        }
    }
    return true;
}

int main() {
    vector<string> bulbs(10);
    for (auto& row : bulbs) cin >> row;

    int answer = 1e9;
    for (int state = 0; state < (1 << 10); state++) {
        vector<string> temp(bulbs);
        int count = 0;

        for (int c = 0; c < 10; c++) {
            if (state & (1 << c)) {
                flip(temp, 0, c);
                count++;
            }
        }

        for (int r = 1; r < 10; r++) {
            for (int c = 0; c < 10; c++) {
                if (temp[r - 1][c] == 'O') {
                    flip(temp, r, c);
                    count++;
                }
            }
        }

        if (allOff(temp)) answer = min(answer, count);
    }

    cout << (answer == 1e9 ? -1 : answer);

    return 0;
}
