#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> scores(N);
    for (int i = 0; i < N; i++) {
        std::cin >> scores[i];
    }

    int maxScore = *std::max_element(scores.begin(), scores.end());
    double sum = 0.0;
    for (int i = 0; i < N; i++) {
        sum += (double)scores[i] / maxScore * 100;
    }

    double average = sum / N;
    std::cout << std::fixed;
    std::cout.precision(6);
    std::cout << average << std::endl;

    return 0;
}
