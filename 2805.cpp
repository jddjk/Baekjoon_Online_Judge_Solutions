#include <iostream>
#include <vector>
using namespace std;

long long calculateWood(vector<int>& trees, int height) {
    long long totalWood = 0;
    for (int i = 0; i < trees.size(); i++) {
        if (trees[i] > height) {
            totalWood += trees[i] - height;
        }
    }
    return totalWood;
}

int findMaxHeight(vector<int>& trees, int targetWood) {
    int left = 0;
    int right = 1000000000;
    int maxHeight = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        long long wood = calculateWood(trees, mid);

        if (wood >= targetWood) {
            maxHeight = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return maxHeight;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> trees(N);
    for (int i = 0; i < N; i++) {
        cin >> trees[i];
    }

    int maxHeight = findMaxHeight(trees, M);

    cout << maxHeight << endl;

    return 0;
}
