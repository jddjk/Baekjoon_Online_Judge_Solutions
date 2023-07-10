#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    vector<int> arr(N+1, 0);
    for (int i=1; i<=N; ++i)
        cin >> arr[i];
        
    vector<vector<int>> dp(N+1, vector<int>(N+1, 0));
    for (int i=1; i<=N; ++i)
        dp[i][i] = 1;
        
    for (int i=1; i<N; ++i)
        if (arr[i] == arr[i+1])
            dp[i][i+1] = 1;
            
    for (int k=3; k<=N; ++k) {
        for (int i=1; i<=N-k+1; ++i) {
            int j = i+k-1;
            if (arr[i] == arr[j] && dp[i+1][j-1])
                dp[i][j] = 1;
        }
    }

    int M;
    cin >> M;
    while(M--) {
        int S, E;
        cin >> S >> E;
        cout << dp[S][E] << "\n";
    }

    return 0;
}
