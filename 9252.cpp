#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int dp[1001][1001];
int track[1001][1001];

int main() {
    string a, b;
    cin >> a >> b;
    a = " " + a;
    b = " " + b;

    for (int i = 1; i < a.size(); i++) {
        for (int j = 1; j < b.size(); j++) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                track[i][j] = 1;
            }
            else {
                if (dp[i - 1][j] < dp[i][j - 1]) {
                    dp[i][j] = dp[i][j - 1];
                    track[i][j] = 2;
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                    track[i][j] = 3;
                }
            }
        }
    }

    cout << dp[a.size() - 1][b.size() - 1] << "\n";

    if (dp[a.size() - 1][b.size() - 1] != 0) {
        string ans = "";
        int x = a.size() - 1;
        int y = b.size() - 1;
        while (track[x][y]) {
            if (track[x][y] == 1) {
                ans = a[x] + ans;
                x--;
                y--;
            }
            else if (track[x][y] == 2) {
                y--;
            }
            else {
                x--;
            }
        }
        cout << ans;
    }

    return 0;
}
