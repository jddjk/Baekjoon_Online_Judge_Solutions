#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    unordered_map<int, int> cardCount;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        cardCount[num]++;
    }

    int M;
    cin >> M;

    vector<int> targets(M);
    for (int i = 0; i < M; i++) {
        cin >> targets[i];
    }

    for (int i = 0; i < M; i++) {
        cout << cardCount[targets[i]] << " ";
    }

    return 0;
}
