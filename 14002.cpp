#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<int> sequence(N);
    for (int i = 0; i < N; ++i) {
        cin >> sequence[i];
    }

    vector<int> dp(N, 1);
    vector<int> trace(N, -1);
    int idx = 0;
    
    for(int i = 1; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(sequence[j] < sequence[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                trace[i] = j;
            }
        }
        if(dp[idx] < dp[i])
            idx = i;
    }

    vector<int> LIS;
    while(idx != -1) {
        LIS.push_back(sequence[idx]);
        idx = trace[idx];
    }

    cout << LIS.size() << "\n";
    for(auto i = LIS.rbegin(); i != LIS.rend(); i++) {
        cout << *i << ' ';
    }

    return 0;
}
