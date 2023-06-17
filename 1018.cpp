#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countRepaints(vector<string>& board, int row, int col) {
    int repaints = 0;
    char color = board[row][col];

    for (int i = row; i < row + 8; i++) {
        for (int j = col; j < col + 8; j++) {
            if (board[i][j] != color) {
                repaints++;
            }
            color = (color == 'W') ? 'B' : 'W';
        }
        color = (color == 'W') ? 'B' : 'W';
    }

    return min(repaints, 64 - repaints);
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> board(N);
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    int minRepaints = 64;

    for (int i = 0; i <= N - 8; i++) {
        for (int j = 0; j <= M - 8; j++) {
            int repaints = countRepaints(board, i, j);
            minRepaints = min(minRepaints, repaints);
        }
    }

    cout << minRepaints << endl;

    return 0;
}
