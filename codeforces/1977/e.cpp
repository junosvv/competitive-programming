#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define mii map<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    auto solve = [&]() {
        int n;
        cin >> n;

        auto query = [&](int x, int y) {
            if (x == 0) return true;
            cout << "? " << x << ' ' << y << endl;
            string s;
            cin >> s;
            return s == "YES";
        };

        vi black = {0}, white = {1}, unsure = {}, res(n);
        FOR(u, 2, n+1) {
            if (unsure.empty()) {
                bool toblack = query(black.back(), u), towhite = query(white.back(), u);
                if (toblack && towhite) unsure.push_back(u);
                else if (toblack) black.push_back(u);
                else white.push_back(u);
            } else {
                if (query(unsure.back(), u)) unsure.push_back(u);
                else {
                    if (query(black.back(), u)) {
                        black.push_back(u);
                        for (int v : unsure) white.push_back(v);
                    } else {
                        white.push_back(u);
                        for (int v : unsure) black.push_back(v);
                    }
                    unsure.clear();
                }
            }
        }
        for (int v : white) res[v-1] = 1;
        cout << "! ";
        FOR(v, 0, n) cout << res[v] << ' ';
        cout << endl;
    };

    int T;
    cin >> T;
    FOR(t, 0, T) {
        solve();
    }
}