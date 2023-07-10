#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());

    int left = 0, right = n - 1;
    int minSum = 2e9 + 1;
    int answerLeft = 0, answerRight = 0;

    while (left < right) {
        int sum = v[left] + v[right];

        if (abs(sum) < minSum) {
            minSum = abs(sum);
            answerLeft = v[left];
            answerRight = v[right];
        }

        if (sum < 0) {
            left++;
        } else {
            right--;
        }
    }

    cout << answerLeft << " " << answerRight << "\n";

    return 0;
}
