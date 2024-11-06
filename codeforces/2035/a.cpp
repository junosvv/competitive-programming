#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    auto solve = [&]() {
        int R, C, r, c;
        cin >> R >> C >> r >> c;
        cout << (R-r) * (2*C-1) + (C-c) << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}