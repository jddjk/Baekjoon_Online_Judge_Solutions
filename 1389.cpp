#include <iostream>
#include <vector>
#define INF 10000000
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> matrix(N+1, vector<int>(N+1, INF));
    
    for(int i = 1; i <= N; i++){
        matrix[i][i] = 0;
    }
    
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        matrix[a][b] = 1;
        matrix[b][a] = 1;
    }
    
    for(int k = 1; k <= N; k++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(matrix[i][j] > matrix[i][k] + matrix[k][j]){
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }
    
    int result = INF;
    int person = 0;
    
    for(int i = 1; i <= N; i++){
        int sum = 0;
        for(int j = 1; j <= N; j++){
            sum += matrix[i][j];
        }
        if(result > sum){
            result = sum;
            person = i;
        }
    }
    
    cout << person;
    
    return 0;
}
