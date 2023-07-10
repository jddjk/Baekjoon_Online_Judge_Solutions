#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    int count = 0;
    int num = 666;
    string title;

    while (count < N) {
        if (to_string(num).find("666") != string::npos) {
            count++;
        }
        if (count == N) {
            title = to_string(num);
        }
        num++;
    }

    cout << title << endl;

    return 0;
}
