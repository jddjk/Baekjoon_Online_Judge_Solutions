#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    set<string> unheard;
    vector<string> result;

    for (int i = 0; i < N; i++) {
        string name;
        cin >> name;
        unheard.insert(name);
    }

    for (int i = 0; i < M; i++) {
        string name;
        cin >> name;
        if(unheard.count(name)) {
            result.push_back(name);
        }
    }

    sort(result.begin(), result.end());

    cout << result.size() << "\n";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << "\n";
    }

    return 0;
}
