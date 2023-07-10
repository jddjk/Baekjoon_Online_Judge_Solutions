#include <iostream>
#include <cmath>
#include <vector>
#include <array>
using namespace std;

vector<array<int, 2>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

double calculateProbability(int posX, int posY, int currentDepth, int maxDepth, double currentProb, vector<vector<bool>>& isVisited, const vector<double>& moveProb) {
    if (currentDepth == maxDepth) {
        return currentProb;
    }
    
    isVisited[posX][posY] = true;
    double totalProb = 0.0;

    for (int i = 0; i < 4; ++i) {
        int nextX = posX + directions[i][0];
        int nextY = posY + directions[i][1];

        if (!isVisited[nextX][nextY])
            totalProb += calculateProbability(nextX, nextY, currentDepth + 1, maxDepth, currentProb * moveProb[i], isVisited, moveProb);
    }
    
    isVisited[posX][posY] = false;
    return totalProb;
}

int main() {
    int maxDepth;
    cin >> maxDepth;
    vector<double> moveProb(4);
    for(int i = 0; i < 4; i++) {
        int p;
        cin >> p;
        moveProb[i] = p / 100.0;
    }
    vector<vector<bool>> isVisited(30, vector<bool>(30, false));

    double totalProb = calculateProbability(15, 15, 0, maxDepth, 1.0, isVisited, moveProb);
    cout.precision(10);
    cout << fixed << totalProb << endl;

    return 0;
}
