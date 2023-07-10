#include <iostream>
#include <algorithm>
using namespace std;

#define INF 100000001
int n, m;
int cost[101][101];

int main() {
    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i == j) cost[i][j] = 0;
            else cost[i][j] = INF;
        }
    }
    
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        cost[a][b] = min(cost[a][b], c);
    }

    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(cost[i][j] == INF) printf("0 ");
            else printf("%d ", cost[i][j]);
        }
        printf("\n");
    }

    return 0;
}
