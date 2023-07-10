#include <iostream>
#define MOD 1000000
using namespace std;

typedef long long ll;

struct Matrix {
    ll a, b, c, d;
};

Matrix multiply(Matrix x, Matrix y) {
    Matrix result;
    result.a = (x.a * y.a + x.b * y.c) % MOD;
    result.b = (x.a * y.b + x.b * y.d) % MOD;
    result.c = (x.c * y.a + x.d * y.c) % MOD;
    result.d = (x.c * y.b + x.d * y.d) % MOD;
    return result;
}

Matrix power(Matrix x, ll n) {
    Matrix result;
    result.a = 1;
    result.b = 0;
    result.c = 0;
    result.d = 1;
    while(n > 0) {
        if(n % 2 == 1) {
            result = multiply(result, x);
        }
        x = multiply(x, x);
        n /= 2;
    }
    return result;
}

int main() {
    ll n;
    cin >> n;
    Matrix m;
    m.a = m.b = m.c = 1;
    m.d = 0;
    if(n==0) cout << 0;
    else if(n==1) cout << 1;
    else {
        Matrix result = power(m, n-1);
        cout << result.a % MOD;
    }
    return 0;
}
