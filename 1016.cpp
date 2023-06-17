#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef unsigned long long ull;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ull minVal, maxVal;
    cin >> minVal >> maxVal;

    vector<bool> isNotSqN(maxVal - minVal + 1, true);

    for (ull i = 2; i * i <= maxVal; i++) {
        ull start = (minVal / (i * i)) * (i * i);
        if (start < minVal) {
            start += i * i;
        }
        for (ull j = start; j <= maxVal; j += (i * i)) {
            isNotSqN[j - minVal] = false;
        }
    }

    int count = 0;
    for (bool value : isNotSqN) {
        if (value) {
            count++;
        }
    }

    cout << count << '\n';

    return 0;
}
