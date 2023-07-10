#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1000001

using namespace std;

int N;
int arr[MAX];
long long tree[MAX];
vector<pair<int, int>> v;

long long sum(int i) {
    long long ans = 0;
    while (i > 0) {
        ans += tree[i];
        i -= (i & -i);
    }
    return ans;
}

void update(int i, int diff) {
    while (i <= N) {
        tree[i] += diff;
        i += (i & -i);
    }
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        v.push_back({ arr[i], i });
    }

    sort(v.begin(), v.end());

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += sum(N) - sum(v[i].second);
        update(v[i].second, 1);
    }

    cout << ans << "\n";
    return 0;
}
