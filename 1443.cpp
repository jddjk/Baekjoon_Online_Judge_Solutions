#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

int D, P, result;
unordered_map<long long, bool> visit_nums;

int count_digits(long long value) {
    int cnt = 0;
    while (value > 0) {
        cnt++;
        value /= 10;
    }
    return cnt;
}

void calculate_max(int d, int cnt, long long value) {
    if (visit_nums.count(cnt * 1e10 + value) || count_digits(value) > d)
        return;
    
    visit_nums[cnt * 1e10 + value] = true;
    
    if (cnt == P) {
        result = max(result, (int)value);
        return;
    }
    
    for (int v = 2; v <= 9; v++) {
        calculate_max(d, cnt + 1, value * v);
    }
}

int main() {
    cin >> D >> P;
    result = -1;

    if (P == 0) {
        result = 1;
    } else if (P == 1) {
        result = 9;
    } else if (count_digits((long long)pow(2, P)) > D) {
        result = -1;
    } else {
        calculate_max(D, 0, 1);
    }

    cout << result << '\n';

    return 0;
}
