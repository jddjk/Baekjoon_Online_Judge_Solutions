#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    if(a.second == b.second) {
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }
}

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> meetings(N);

    for (int i = 0; i < N; i++) {
        cin >> meetings[i].first >> meetings[i].second;
    }

    sort(meetings.begin(), meetings.end(), cmp);

    int maxMeetings = 0;
    int endTime = 0;

    for (int i = 0; i < N; i++) {
        if (meetings[i].first >= endTime) {
            endTime = meetings[i].second;
            maxMeetings++;
        }
    }

    cout << maxMeetings << '\n';

    return 0;
}
