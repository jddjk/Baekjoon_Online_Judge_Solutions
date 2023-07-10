#include <iostream>
#include <vector>

using namespace std;

int white = 0, blue = 0; 
vector<vector<int>> board;

void divide_and_conquer(int x, int y, int size) {
    int color = board[x][y];
    bool check = true;

    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if(board[i][j] != color){
                check = false;
                break;
            }
        }
        if(!check)
            break;
    }

    if(check){
        if(color == 0) white++;
        else blue++;
    }
    else{
        int newSize = size / 2;

        divide_and_conquer(x, y, newSize); 
        divide_and_conquer(x, y + newSize, newSize);
        divide_and_conquer(x + newSize, y, newSize);
        divide_and_conquer(x + newSize, y + newSize, newSize);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    board.resize(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    
    divide_and_conquer(0, 0, n);
    
    cout << white << "\n";
    cout << blue << "\n";
    
    return 0;
}
