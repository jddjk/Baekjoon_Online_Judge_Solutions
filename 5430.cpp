#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--) {
        string functions;
        cin >> functions;

        int n;
        cin >> n;

        deque<int> dq;
        string array;
        cin >> array;

        int num = 0;
        for (char ch : array) {
            if ('0' <= ch && ch <= '9') {
                num = num * 10 + (ch - '0');
            }
            else if (ch == ',') {
                dq.push_back(num);
                num = 0;
            }
        }
        if(num != 0) {
            dq.push_back(num);
        }

        bool error = false;
        bool isReversed = false;
        for (char func : functions) {
            if (func == 'R') {
                isReversed = !isReversed;
            }
            else if (func == 'D') {
                if (dq.empty()) {
                    error = true;
                    cout << "error" << '\n';
                    break;
                }
                if (isReversed) {
                    dq.pop_back();
                }
                else {
                    dq.pop_front();
                }
            }
        }

        if (!error) {
            if (isReversed) {
                std::reverse(dq.begin(), dq.end());
            }
            cout << '[';
            while (!dq.empty()) {
                cout << dq.front();
                dq.pop_front();
                if (!dq.empty()) {
                    cout << ',';
                }
            }
            cout << ']' << '\n';
        }
    }

    return 0;
}
