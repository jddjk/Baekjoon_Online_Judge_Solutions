#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    string S;
    cin >> S;

    int cnt = 0, pattern = 0, result = 0;
    for (int i = 1; i < M - 1; i++) {
        if (S[i - 1] == 'I' && S[i] == 'O' && S[i + 1] == 'I') {
            cnt++;
            if (cnt == N) {
                cnt--;
                result++;
            }
            i++;
        }
        else {
            cnt = 0;
        }
    }

    cout << result;

    return 0;
}
