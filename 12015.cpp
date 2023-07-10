#include <iostream>
#include <vector>
using namespace std;

int lower_bound(vector<int>& lis, int target) {
    int start = 0;
    int end = lis.size();
    
    while (start < end) {
        int mid = (start + end) / 2;
        
        if (lis[mid] >= target) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    
    return start;
}

int main() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    vector<int> lis;
    
    for (int i = 0; i < N; i++) {
        if (lis.empty() || A[i] > lis.back()) {
            lis.push_back(A[i]);
        } else {
            int idx = lower_bound(lis, A[i]);
            lis[idx] = A[i];
        }
    }
    
    int max_length = lis.size();
    cout << max_length << endl;
    
    return 0;
}
