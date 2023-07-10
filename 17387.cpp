#include <iostream>
using namespace std;

typedef long long ll;

struct Point {
    ll x, y;
    Point() {}
    Point(ll x, ll y) : x(x), y(y) {}
    bool operator <(const Point& A) {
        if (x != A.x) return x < A.x;
        return y < A.y;
    }
    bool operator <=(const Point& A) {
        if (x != A.x) return x < A.x;
        return y <= A.y;
    }
};

ll ccw(Point A, Point B, Point C) {
    ll op = A.x*B.y + B.x*C.y + C.x*A.y;
    op -= (A.y*B.x + B.y*C.x + C.y*A.x);
    if (op > 0) return 1;
    else if (op == 0) return 0;
    else return -1;
}

bool isCross(Point A, Point B, Point C, Point D) {
    ll ab = ccw(A, B, C)*ccw(A, B, D);
    ll cd = ccw(C, D, A)*ccw(C, D, B);
    if (ab == 0 && cd == 0) {
        if (B < A) swap(A, B);
        if (D < C) swap(C, D);
        return C <= B && A <= D;
    }
    return ab <= 0 && cd <= 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Point A, B, C, D;
    cin >> A.x >> A.y >> B.x >> B.y;
    cin >> C.x >> C.y >> D.x >> D.y;

    cout << isCross(A, B, C, D) << '\n';
    return 0;
}
