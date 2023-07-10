#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        queue<pair<int, int>> documents;
        priority_queue<int> priority;

        for (int i = 0; i < N; i++) {
            int importance;
            cin >> importance;
            documents.push(make_pair(importance, i));
            priority.push(importance);
        }

        int count = 0;
        while (!documents.empty()) {
            int curPriority = documents.front().first;
            int curIndex = documents.front().second;
            documents.pop();

            if (curPriority == priority.top()) {
                priority.pop();
                count++;

                if (curIndex == M) {
                    cout << count << endl;
                    break;
                }
            } else {
                documents.push(make_pair(curPriority, curIndex));
            }
        }
    }
    return 0;
}
