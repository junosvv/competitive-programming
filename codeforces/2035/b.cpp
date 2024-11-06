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
        int n;
        cin >> n;
        if (n == 1 || n == 3) cout << "-1\n";
        else if (n&1) {
            FOR(i, 0, n-4) cout << 3;
            cout << "6366\n";
        } else {
            FOR(i, 0, n-2) cout << 3;
            cout << "66\n";
        }
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}