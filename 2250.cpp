#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10001
using namespace std;

int N, node_idx;
vector<pair<int, int>> tree(MAX);
int parent[MAX];
int level_min[MAX], level_max[MAX];

void inOrder(int node, int depth) {
    if (tree[node].first != -1)
        inOrder(tree[node].first, depth + 1);

    level_min[depth] = min(level_min[depth], node_idx);
    level_max[depth] = max(level_max[depth], node_idx);
    node_idx++;

    if (tree[node].second != -1)
        inOrder(tree[node].second, depth + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int node, left, right;
        cin >> node >> left >> right;
        tree[node] = {left, right};
        if(left != -1) parent[left] = node;
        if(right != -1) parent[right] = node;
        level_min[i+1] = MAX;
    }

    int root = 1;
    while (parent[root] != 0) root = parent[root];

    node_idx = 1;
    inOrder(root, 1);

    int result_level = 1, result_width = level_max[1] - level_min[1] + 1;
    for (int i = 2; i <= N; i++) {
        int width = level_max[i] - level_min[i] + 1;
        if (result_width < width) {
            result_level = i;
            result_width = width;
        }
    }

    cout << result_level << ' ' << result_width << '\n';

    return 0;
}
