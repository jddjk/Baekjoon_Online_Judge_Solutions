#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    vector<pair<int, int>> matrix(N+1);
    vector<vector<int>> dp(N+1, vector<int>(N+1, 0));

    for (int i=1; i<=N; ++i) {
        cin >> matrix[i].first >> matrix[i].second;
    }

    for (int gap=1; gap<N; ++gap) {
        for (int i=1; i<=N-gap; ++i) {
            int j = i + gap;
            dp[i][j] = INT_MAX;
            for (int k=i; k<j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + matrix[i].first*matrix[k].second*matrix[j].second);
            }
        }
    }

    cout << dp[1][N] << "\n";

    return 0;
}
