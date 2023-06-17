#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>

using namespace std;

vector<int> find_locations(int T, vector<tuple<int, int, int, int, int, int>> &test_cases) {
    vector<int> results;
    for (int t = 0; t < T; t++) {
        int x1, y1, r1, x2, y2, r2;
        x1 = get<0>(test_cases[t]);
        y1 = get<1>(test_cases[t]);
        r1 = get<2>(test_cases[t]);
        x2 = get<3>(test_cases[t]);
        y2 = get<4>(test_cases[t]);
        r2 = get<5>(test_cases[t]);

        double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

        if (distance == 0 && r1 == r2) {
            results.push_back(-1);
        } else if (abs(r1 - r2) < distance && distance < r1 + r2) {
            results.push_back(2);
        } else if (distance == r1 + r2 || distance == abs(r1 - r2)) {
            results.push_back(1);
        } else {
            results.push_back(0);
        }
    }
    return results;
}

int main() {
    int T;
    cin >> T;

    vector<tuple<int, int, int, int, int, int>> test_cases(T);
    for (int i = 0; i < T; i++) {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        test_cases[i] = make_tuple(x1, y1, r1, x2, y2, r2);
    }

    vector<int> results = find_locations(T, test_cases);
    for (int res : results) {
        cout << res << endl;
    }

    return 0;
}
