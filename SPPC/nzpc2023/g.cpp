#include <bits/stdc++.h>

using namespace std;

int main() {
    string cards[12];
    for (int i = 0; i < 12; i++) {
        cin >> cards[i];

    }
    // typedef tuple<int, int, int> t;

    auto is_fine = [&](char i, char j, char k) {
        if (i == j && j == k) return true;
        if (i != j && j != k && i != k) return true;
        return false;
    };

    auto is_set = [&](int i, int j, int k) {
        for (int d=0; d<4; d++) {
            if (!is_fine(cards[i][d], cards[j][d], cards[k][d])) return false;
        }
        return true;
    };

    for (int i=0; i<12; i++) {
        for (int j=i+1; j<12; j++) {
            for (int k=j+1; k<12; k++) {
                if (is_set(i, j, k)) cout << i+1 << ' ' << j+1 << ' ' << k+1 << '\n';
            }
        }
    }
}