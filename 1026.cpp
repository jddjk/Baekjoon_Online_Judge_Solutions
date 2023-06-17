#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int main() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    vector<int> B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), compare);
    
    int S = 0;
    for (int i = 0; i < N; i++) {
        S += A[i] * B[i];
    }
    
    cout << S << endl;
    
    return 0;
}
