#include <iostream>
#include <vector>
using namespace std;

int parent[51];
int party[51][51];
bool truth[51];
vector<int> know;

int find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if(u != v) parent[u] = v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    for(int i=1; i<=N; i++)
        parent[i] = i;

    int num_truth;
    cin >> num_truth;
    for(int i=0; i<num_truth; i++){
        int person;
        cin >> person;
        know.push_back(person);
    }

    for(int i=1; i<=M; i++){
        cin >> party[i][0];
        for(int j=1; j<=party[i][0]; j++){
            cin >> party[i][j];
            if(j > 1) merge(party[i][1], party[i][j]);
        }
    }

    for(int i=0; i<num_truth; i++)
        truth[find(know[i])] = true;

    int answer = M;
    for(int i=1; i<=M; i++){
        for(int j=1; j<=party[i][0]; j++){
            if(truth[find(party[i][j])]){
                answer--;
                break;
            }
        }
    }

    cout << answer << "\n";

    return 0;
}
