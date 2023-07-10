#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long K, N;
    cin >> K >> N;
    vector<long long> line(K);
    for (int i = 0; i < K; i++) {
        cin >> line[i];
    }

    long long low = 1, high = *max_element(line.begin(), line.end());

    while (low <= high) {
        long long mid = (low + high) / 2;
        long long cnt = 0;

        for (int i = 0; i < K; i++) {
            cnt += line[i] / mid;
        }

        if (cnt >= N) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    cout << high << "\n";

    return 0;
}
