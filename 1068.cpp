#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> a[50];
int root, remove_node;
bool visited[50];
int leaf_count = 0;

void dfs(int node) {
    visited[node] = true;

    bool leaf = true;
    for(int child : a[node]) {
        if(child != remove_node && !visited[child]) {
            leaf = false;
            dfs(child);
        }
    }

    if(leaf) leaf_count++;
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        int parent;
        cin >> parent;
        if(parent == -1) {
            root = i;
            continue;
        }
        a[parent].push_back(i);
    }

    cin >> remove_node;
    if(remove_node == root) {
        cout << 0 << endl;
    } else {
        dfs(root);
        cout << leaf_count << endl;
    }

    return 0;
}
