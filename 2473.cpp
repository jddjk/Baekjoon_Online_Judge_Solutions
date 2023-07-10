#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<ll> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    ll closest = LLONG_MAX;
    ll res[3];

    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            ll sum = arr[i] + arr[left] + arr[right];

            if (llabs(sum) < closest) {
                closest = llabs(sum);
                res[0] = arr[i];
                res[1] = arr[left];
                res[2] = arr[right];
            }

            if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    sort(res, res + 3);
    cout << res[0] << " " << res[1] << " " << res[2] << "\n";

    return 0;
}
