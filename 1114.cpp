#include <iostream>
#define MAX_LOG 1000000000
using namespace std;

int logLength, numLog, maxCut;
int logs[10001], diffs[10001], i, mid, position;
int longest, firstCut, count, sum, leftLimit = 0, rightLimit = MAX_LOG;

void quicksort(int start, int end) {
    if (start >= end) {
        return;
    }
    int pivot = start;
    int i = pivot + 1;
    int j = end;
    int temp;

    while(i <= j) {
        while(i <= end && logs[i] <= logs[pivot]) {
            i++;
        }
        while(j > start && logs[j] >= logs[pivot]) {
            j--;
        }
        if(i > j) {
            temp = logs[j];
            logs[j] = logs[pivot];
            logs[pivot] = temp;
        } else {
            temp = logs[i];
            logs[i] = logs[j];
            logs[j] = temp;
        }
    }
    quicksort(start, j - 1);
    quicksort(j + 1, end);
}

int main() {
    cin >> logLength >> numLog >> maxCut;
    for(i = 0; i < numLog; i++) cin >> logs[i];
    logs[numLog] = logLength;
    
    quicksort(0, numLog);
    
    diffs[0] = logs[0];
    for(i = 1; i <= numLog; i++) diffs[i] = logs[i] - logs[i - 1];

    while(leftLimit <= rightLimit) {
        mid = (leftLimit + rightLimit) / 2;
        for(position = sum = count = 0, i = numLog; i >= 0; i--) {
            if(diffs[i] > mid) {
                count = maxCut + 1;
                break;
            }
            if(sum + diffs[i] > mid) {
                sum = 0;
                count++;
                position = i;
            }
            sum += diffs[i];
        }
        if(count > maxCut) leftLimit = mid + 1;
        else {
            longest = mid; 
            rightLimit = mid - 1;
            firstCut = count == maxCut ? logs[position] : logs[0];
        }
    }
    cout << longest << " " << firstCut;
    return 0;
}
