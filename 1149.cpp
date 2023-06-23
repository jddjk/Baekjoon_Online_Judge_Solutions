#include <iostream>
#include <algorithm>

using namespace std;

int my_min(int a, int b) {
    return (a < b) ? a : b;
}

int my_min(int a, int b, int c) {
    return my_min(my_min(a, b), c);
}

int main() {
    int N;
    cin >> N;
    int prices[N][3];
    int minimum[N][3];
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> prices[i][j];
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 0) {
                minimum[i][j] = prices [i][j];
            } else {
                minimum[i][j] = prices[i][j] + my_min(minimum[i-1][(j+1)%3], minimum[i-1][(j+2)%3]);
            }
        }
    }
    
    int res = my_min(minimum[N-1][0], minimum[N-1][1], minimum[N-1][2]);
    
    cout << res << endl;
    return 0;
}
