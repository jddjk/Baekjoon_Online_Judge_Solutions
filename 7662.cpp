#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int k;
        cin >> k;

        priority_queue<int> max_heap;
        priority_queue<int, vector<int>, greater<int>> min_heap;
        unordered_map<int, int> m;

        for (int i = 0; i < k; i++) {
            char c;
            int n;
            cin >> c >> n;

            if (c == 'I') {
                max_heap.push(n);
                min_heap.push(n);
                m[n]++;
            }
            else if (c == 'D') {
                if (n == 1 && !max_heap.empty()) {
                    m[max_heap.top()]--;
                    if (m[max_heap.top()] == 0) m.erase(max_heap.top());
                    max_heap.pop();
                }
                else if (n == -1 && !min_heap.empty()) {
                    m[min_heap.top()]--;
                    if (m[min_heap.top()] == 0) m.erase(min_heap.top());
                    min_heap.pop();
                }

                while (!max_heap.empty() && m.find(max_heap.top()) == m.end()) max_heap.pop();
                while (!min_heap.empty() && m.find(min_heap.top()) == m.end()) min_heap.pop();
            }
        }
        if (max_heap.empty() || min_heap.empty()) cout << "EMPTY\n";
        else cout << max_heap.top() << ' ' << min_heap.top() << '\n';
    }
    return 0;
}
