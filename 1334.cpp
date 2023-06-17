#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isBigger(string s1, string s2) {
    if (s1.size() != s2.size())
        return s1.size() > s2.size();

    for (int i = 0; i < s1.size(); ++i)
        if (s1[i] != s2[i])
            return s1[i] > s2[i];
    return false;
}

string addOne(string s) {
    int n = s.size();
    if (s[n - 1] != '9') {
        s[n - 1]++;
    }
    else {
        int i = n - 1;
        while (i >= 0 && s[i] == '9') {
            s[i] = '0';
            i--;
        }
        if (i >= 0)
            s[i]++;
        else
            s = "1" + s;
    }
    return s;
}

string nextPalindrome(string s) {
    int n = s.size();
    if (s == string(n, '9')) {
        s = '1' + string(n - 1, '0') + '1';
        return s;
    }

    string left = s.substr(0, (n + 1) / 2);
    string right = left;
    reverse(right.begin(), right.end());
    if (n % 2 != 0)
        right = right.substr(1);

    string palindrome = left + right;
    if (isBigger(palindrome, s))
        return palindrome;

    left = addOne(left);
    right = left;
    reverse(right.begin(), right.end());
    if (n % 2 != 0)
        right = right.substr(1);

    return left + right;
}

int main() {
    string N;
    cin >> N;
    cout << nextPalindrome(N) << endl;
    return 0;
}
