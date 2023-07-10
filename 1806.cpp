#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, S;
    cin >> N >> S;

    vector<int> arr(N);
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    int start = 0, end = 0, sum = 0, minLength = INT_MAX;

    while(true) {
        if(sum >= S) {
            minLength = min(minLength, end - start);
            sum -= arr[start++];
        }
        else if(end == N) break;
        else sum += arr[end++];
    }

    if(minLength == INT_MAX) cout << 0 << '\n';
    else cout << minLength << '\n';

    return 0;
}
