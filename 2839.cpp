#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int count = 0;

    while (N % 5 != 0 && N >= 3) {
        N -= 3;
        count++;
    }

    if (N % 5 == 0) {
        count += N / 5;
    } else if (N % 5 != 0 && N % 3 == 0) {
        count += N / 3;
    } else {
        count = -1;
    }

    cout << count << endl;

    return 0;
}
