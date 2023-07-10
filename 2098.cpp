#include <iostream>
#include <algorithm>
using namespace std;

#define INF 987654321
#define MAX 16

int N;
int W[MAX][MAX];
int dp[MAX][1 << MAX];

int TSP(int current, int visited) {
    if (visited == (1 << N) - 1) {
        if (W[current][0] != 0) {
            return W[current][0];
        }
        else {
            return INF;
        }
    }

    if (dp[current][visited] != -1) {
        return dp[current][visited];
    }

    dp[current][visited] = INF;
    for (int i = 0; i < N; i++) {
        if ((visited & (1 << i)) == 0 && W[current][i] != 0) {
            dp[current][visited] = min(dp[current][visited], TSP(i, visited + (1 << i)) + W[current][i]);
        }
    }
    return dp[current][visited];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> W[i][j];
        }
    }

    for (int i = 0; i < MAX; i++) {
        fill(dp[i], dp[i] + (1 << MAX), -1);
    }

    cout << TSP(0, 1) << "\n";

    return 0;
}
