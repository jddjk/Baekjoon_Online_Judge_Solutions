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

    vector<int> dp;
    dp.push_back(sequence[0]);
    for (int i = 1; i < N; ++i) {
        if (sequence[i] > dp.back()) {
            dp.push_back(sequence[i]);
        } else {
            auto it = lower_bound(dp.begin(), dp.end(), sequence[i]);
            *it = sequence[i];
        }
    }
    
    cout << dp.size();

    return 0;
}
