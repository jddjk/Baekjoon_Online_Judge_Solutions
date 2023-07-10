#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> inOrder, postOrder;
int position[100001];

void preOrder(int inStart, int inEnd, int postStart, int postEnd) {
    if(inStart > inEnd || postStart > postEnd) return;
    int root = postOrder[postEnd];
    cout << root << ' ';

    preOrder(inStart, position[root] - 1, postStart, postStart + (position[root] - inStart) - 1);
    preOrder(position[root] + 1, inEnd, postStart + (position[root] - inStart), postEnd - 1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    inOrder = vector<int>(n);
    postOrder = vector<int>(n);
    for(int i = 0; i < n; i++) {
        cin >> inOrder[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> postOrder[i];
    }
    for(int i = 0; i < n; i++) {
        position[inOrder[i]] = i;
    }
    preOrder(0, n - 1, 0, n - 1);
    return 0;
}
