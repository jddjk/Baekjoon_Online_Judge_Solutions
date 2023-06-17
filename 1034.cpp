#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
vector<string> lamps;

int bit_count(string str){
    int count = 0;
    for (char c : str)
        if (c == '0')
            count++;
    return count;
}

int main(){
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        lamps.push_back(str);
    }
    cin >> K;

    int max_rows = 0;
    for (string row : lamps) {
        if (bit_count(row) <= K && bit_count(row) % 2 == K % 2) {
            max_rows = max(max_rows, (int)count(lamps.begin(), lamps.end(), row));
        }
    }
    cout << max_rows << "\n";

    return 0;
}
