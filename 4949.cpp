#include <iostream>
#include <stack>
using namespace std;

string isBalanced(const string& str) {
    stack<char> st;

    for (char c : str) {
        if (c == '(' || c == '[') {
            st.push(c);
        } else if (c == ')') {
            if (st.empty() || st.top() != '(') {
                return "no";
            }
            st.pop();
        } else if (c == ']') {
            if (st.empty() || st.top() != '[') {
                return "no";
            }
            st.pop();
        }
    }

    if (st.empty()) {
        return "yes";
    } else {
        return "no";
    }
}

int main() {
    string input;

    while (true) {
        getline(cin, input);

        if (input == ".") {
            break;
        }

        cout << isBalanced(input) << endl;
    }

    return 0;
}
