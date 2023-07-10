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

    vector<int> lis;
    vector<pair<int, int>> trace(N);
    lis.push_back(sequence[0]);
    trace[0].first = 0;
    trace[0].second = sequence[0];

    for (int i = 1; i < N; ++i) {
        if (sequence[i] > lis.back()) {
            trace[i].first = lis.size();
            lis.push_back(sequence[i]);
        } else {
            int idx = lower_bound(lis.begin(), lis.end(), sequence[i]) - lis.begin();
            lis[idx] = sequence[i];
            trace[i].first = idx;
        }
        trace[i].second = sequence[i];
    }
    
    cout << lis.size() << '\n';
    
    int idx = lis.size() - 1;
    vector<int> result;
    for (int i = N-1; i >= 0; --i) {
        if (trace[i].first == idx) {
            result.push_back(trace[i].second);
            --idx;
        }
    }

    for (auto iter = result.rbegin(); iter != result.rend(); ++iter) {
        cout << *iter << ' ';
    }

    return 0;
}
