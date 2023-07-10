#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, temp;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> temp;

        bool found = false;
        int left = 0;
        int right = v.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (v[mid] == temp) {
                found = true;
                break;
            } else if (v[mid] < temp) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        cout << found << '\n';
    }

    return 0;
}
