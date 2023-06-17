#include <iostream>
#include <cmath>

#define WHITE 0
#define BLACK 1

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int Time, N, K, R1, R2, C1, C2;
    cin >> Time >> N >> K >> R1 >> R2 >> C1 >> C2;

    int Biggest = pow(N, Time);

    auto is_middle = [N, K](int r, int c, int k) {
        int sp = (N - K) / 2;
        int fp = sp + K;
        return (sp <= r && r < fp) && (sp <= c && c < fp);
    };

    auto getColor = [&](int r, int c) {
        int t_big = Biggest;
        int tr = r, tc = c, pr, pc;
        while ((t_big /= N) != 0) {
            pr = tr / t_big;
            pc = tc / t_big;
            if (is_middle(pr, pc, t_big / N)) {
                return BLACK;
            }
            tr -= (pr * t_big);
            tc -= (pc * t_big);
        }
        return WHITE;
    };

    for (int i = R1; i <= R2; i++) {
        for (int j = C1; j <= C2; j++) {
            cout << getColor(i, j);
        }
        cout << '\n';
    }

    return 0;
}
