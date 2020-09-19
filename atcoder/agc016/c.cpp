#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define lg long long

template <class T> ostream& operator<<(ostream& os, vector<T>& x) {
    os << '[';
    bool first = true;
    for (T i : x) {
        if (!first) os << ", ";
        first = false;
        os << i;
    }
    return os << ']';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int R, C, RR, CC;
    cin >> R >> C >> RR >> CC;

    if (R%RR == 0 && C%CC == 0) {
        cout << "No" << '\n';
        exit(0);
    }

    cout << "Yes" << '\n';

    bool swapped = false;
    if (C%CC == 0) {
        swapped = true;
        swap(R, C);
        swap(RR, CC);
    }

    vector<vector<int>> grid(R, vector<int>(C));
    
    int x = C/CC + 1;
    FOR(r, 0, R) FOR(c, 0, C) {
        if (c%CC == 0) grid[r][c] = x;
        else if ((c+1)%CC == 0) grid[r][c] = -x-1;
    }
    
    if (swapped) {
        FOR(c, 0, C) {
            FOR(r, 0, R) cout << grid[r][c] << ' ';
            cout << '\n';
        }
    } else {
        FOR(r, 0, R) {
            FOR(c, 0, C) cout << grid[r][c] << ' ';
            cout << '\n';
        }
    }
}
