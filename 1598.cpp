#include <iostream>
#include <cmath>
using namespace std;

pair<int, int> position(int number) {
    int row = (number - 1) / 4 + 1;
    int column = number % 4;
    if (column == 0) column = 4;
    return {row, column};
}

int main() {
    int A, B;
    cin >> A >> B;
    pair<int, int> posA = position(A);
    pair<int, int> posB = position(B);

    int result = abs(posA.first - posB.first) + abs(posA.second - posB.second);
    cout << result << endl;

    return 0;
}
