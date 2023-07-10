#include <iostream>
using namespace std;

int sudoku[9][9];

bool check(int row, int col, int num) {
    for (int i = 0; i < 9; i++) {
        if (sudoku[i][col] == num || sudoku[row][i] == num)
            return false;
    }
    int startRow = row / 3 * 3;
    int startCol = col / 3 * 3;
    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (sudoku[i][j] == num)
                return false;
        }
    }
    return true;
}

void dfs(int cnt) {
    if (cnt == 81) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << sudoku[i][j];
            }
            cout << '\n';
        }
        exit(0);
    }

    int x = cnt / 9;
    int y = cnt % 9;

    if (sudoku[x][y] == 0) {
        for (int i = 1; i <= 9; i++) {
            if (check(x, y, i)) {
                sudoku[x][y] = i;
                dfs(cnt + 1);
                sudoku[x][y] = 0;
            }
        }
    } else {
        dfs(cnt + 1);
    }
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%1d", &sudoku[i][j]);
        }
    }
    dfs(0);
    return 0;
}
