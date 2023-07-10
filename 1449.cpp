#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, L;
    cin >> N >> L;

    vector<int> locations(N);
    for (int i = 0; i < N; i++) {
        cin >> locations[i];
    }

    sort(locations.begin(), locations.end());

    int count = 1;
    int start = locations[0];
    int end = start + L - 1;

    for (int i = 1; i < N; i++) {
        if (locations[i] <= end) {
            continue;
        }
        else {
            count++;
            start = locations[i];
            end = start + L - 1;
        }
    }

    cout << count << endl;

    return 0;
}
