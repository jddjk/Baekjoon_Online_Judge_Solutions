#include <iostream>
using namespace std;

double fastPow(double base, int exp) {
    if (exp == 0)
        return 1.0;

    double temp = fastPow(base, exp / 2);
    if (exp % 2 == 0)
        return temp * temp;
    else
        return base * temp * temp;
}

int main() {
    long long s, p;
    cin >> s >> p;

    if (s == p) {
        cout << 1;
        return 0;
    }

    double prev = -1.0;
    for (int i = 2;; i++) {
        double curr = fastPow((double)s / i, i);
        if (prev > curr) {
            cout << -1;
            return 0;
        }
        if (p <= curr) {
            cout << i;
            return 0;
        }
        prev = curr;
    }

    return 0;
}
