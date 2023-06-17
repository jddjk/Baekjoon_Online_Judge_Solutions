#include <iostream>
#include <vector>
#include <cstring>
#define MAXN 16

using namespace std;

int N;
vector<vector<int>> prices;
int dp[MAXN][1 << MAXN][10];

int solve(int current, int visited, int prePrice) {
    if (dp[current][visited][prePrice] != -1) return dp[current][visited][prePrice];
    if (visited == (1 << N) - 1) return 1;

    int ret = 1;
    for (int next = 0; next < N; ++next) {
        if ((visited & (1 << next)) || prices[current][next] < prePrice) continue;
        ret = max(ret, 1 + solve(next, visited | (1 << next), prices[current][next]));
    }

    return dp[current][visited][prePrice] = ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    prices = vector<vector<int>>(N, vector<int>(N));

    for (int i = 0; i < N; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < N; ++j) {
            prices[i][j] = row[j] - '0';
        }
    }

    memset(dp, -1, sizeof(dp));

    cout << solve(0, 1, 0) << "\n";

    return 0;
}
