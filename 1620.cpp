#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    unordered_map<string, int> nameToNum;
    unordered_map<int, string> numToName;
    string name;

    for (int i = 1; i <= N; i++) {
        cin >> name;
        nameToNum[name] = i;
        numToName[i] = name;
    }

    string question;
    for (int i = 0; i < M; i++) {
        cin >> question;
        if (isdigit(question[0])) {
            cout << numToName[stoi(question)] << "\n";
        } else {
            cout << nameToNum[question] << "\n";
        }
    }

    return 0;
}
