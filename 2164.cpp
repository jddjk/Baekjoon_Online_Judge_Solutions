#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    queue<int> cards;

    for (int i = 1; i <= N; i++) {
        cards.push(i);
    }
    
    while (cards.size() > 1) {
        cards.pop();
        int topCard = cards.front();
        cards.pop();
        cards.push(topCard);
    }

    cout << cards.front() << endl;
    
    return 0;
}
