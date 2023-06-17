#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> divisors(n);
    for (int i = 0; i < n; i++) {
        std::cin >> divisors[i];
    }
    std::sort(divisors.begin(), divisors.end());

    long long N = (long long)divisors[0] * divisors[n - 1];
    std::cout << N << std::endl;
    
    return 0;
}
