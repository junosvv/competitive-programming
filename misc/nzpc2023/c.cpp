// c.cpp
#include <bits/stdc++.h>
using namespace std;
int grid[15][5];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char result;
        int row, col;
        cin >> result >> row >> col;
        if (result == 'G') {
            grid[row][col] += 1;
        } else if (result == 'S') {
            grid[row][col] -= 1;
        }
    }
    // Manually find the maximum goals

    vector<pair<int, int>> best;
    int maxScore = 0;
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 5; j++) {
            if (grid[i][j] > maxScore) {
                maxScore = grid[i][j];
                best.clear();
                best.push_back({i,j});
            } else if (grid[i][j] == maxScore) {
                best.push_back({i,j});
            }

        }
    }
    if (best.size() == 1) {
        cout << "Best place " << best[0].first << " " << best[0].second << "." << endl;
    } else {
        cout << "Best places ";
        for (pair<int, int> place: best) {
            cout << place.first << " " << place.second;
            if (place == best.back()) {
                cout << ".\n";
            } else {
                cout << ", ";
            }
        }
    }
}
