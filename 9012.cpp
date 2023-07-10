#include <iostream>
#include <string>
#include <stack>
using namespace std;

string isVPS(const string& str) {
    stack<char> st;

    for (char c : str) {
        if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            if (st.empty() || st.top() != '(') {
                return "NO";
            }
            st.pop();
        }
    }

    if (st.empty()) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        string input;
        cin >> input;

        cout << isVPS(input) << endl;
    }

    return 0;
}
