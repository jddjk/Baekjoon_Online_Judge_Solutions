#include<bits/stdc++.h>
using namespace std;

int largestPrimeFactor[100001];

void calculateLargestPrimeFactors() {
    for (int i=2; i<=100000; i++) {
        if (largestPrimeFactor[i] == 0) {
            for (int j=i; j<=100000; j+=i) {
                largestPrimeFactor[j] = i;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    calculateLargestPrimeFactors();

    int maxNum, limit, count=1;
    cin >> maxNum >> limit;

    for (int i=2; i<=maxNum; i++) {
        if (largestPrimeFactor[i] <= limit) {
            count++;
        }
    }
    cout << count;
    return 0;
}
