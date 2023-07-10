#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> numbers(N);
    map<int, int> frequency;
    int sum = 0;
    
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
        sum += numbers[i];
        frequency[numbers[i]]++;
    }
    
    sort(numbers.begin(), numbers.end());
    
    int average = round((double)sum / N);
    int median = numbers[N/2];
    
    int maxFreq = 0;
    int mode = 0;
    int count = 0;
    
    for (auto it = frequency.begin(); it != frequency.end(); ++it) {
        if (it->second > maxFreq) {
            maxFreq = it->second;
            mode = it->first;
            count = 1;
        } else if (it->second == maxFreq) {
            if (count == 1) {
                mode = it->first;
            }
            count++;
        }
    }
    
    int range = numbers[N-1] - numbers[0];
    
    cout << average << endl;
    cout << median << endl;
    cout << mode << endl;
    cout << range << endl;
    
    return 0;
}
