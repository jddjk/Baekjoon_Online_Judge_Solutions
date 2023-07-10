#include <iostream>

using namespace std;

long long dp[101][10][1<<10];
long long mod = 1e9;

int main() {
    int N;
    cin >> N;
    for(int i = 1; i <= 9; i++) dp[1][i][1<<i] = 1;
    for(int i = 2; i <= N; i++) {
        for(int j = 0; j <= 9; j++) {
            for(int k = 0; k < (1<<10); k++) {
                int temp = k | (1<<j);
                if(j == 0) dp[i][j][temp] = (dp[i][j][temp] + dp[i-1][1][k]) % mod;
                else if(j == 9) dp[i][j][temp] = (dp[i][j][temp] + dp[i-1][8][k]) % mod;
                else dp[i][j][temp] = (dp[i][j][temp] + dp[i-1][j-1][k] + dp[i-1][j+1][k]) % mod;
            }
        }
    }
    long long result = 0;
    for(int i = 0; i <= 9; i++) result = (result + dp[N][i][(1<<10)-1]) % mod;
    cout << result << '\n';
    return 0;
}
