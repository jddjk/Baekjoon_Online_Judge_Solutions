#include <iostream>
#include <vector>

int main() {
    int M;
    std::cin >> M;
    
    std::vector<bool> cups(4, false);
    cups[1] = true;
    
    for (int i = 0; i < M; i++) {
        int X, Y;
        std::cin >> X >> Y;
        
        if (cups[X] || cups[Y]) {
            std::swap(cups[X], cups[Y]);
        }
    }

    for (int i = 1; i <= 3; i++) {
        if (cups[i]) {
            std::cout << i << std::endl;
            return 0;
        }
    }

    std::cout << -1 << std::endl;
    return 0;
}
