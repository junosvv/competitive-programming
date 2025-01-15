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
        int n, m;
        cin >> n >> m;
        if (n >= m) {
            cout << "YES\n";
            FOR(i, 0, 2*n) {
                FOR(j, 0, m) cout << j+1 << ' ';
                cout << '\n';
            }
        } else {
            cout << "NO\n";
        }
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}