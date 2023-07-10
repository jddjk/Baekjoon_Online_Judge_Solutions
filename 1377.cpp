#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    vector<pair<int, int>> A(N + 1);

    for(int i = 1; i <= N; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }

    sort(A.begin()+1, A.end());

    int max_round = 0;
    for(int i = 1; i <= N; i++) {
        if(A[i].second - i > max_round) {
            max_round = A[i].second - i;
        }
    }
    cout << max_round + 1 << '\n';
    return 0;
}
