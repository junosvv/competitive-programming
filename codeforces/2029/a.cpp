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
        int l, r, k;
        cin >> l >> r >> k;
        cout << max(0LL, r/k - l + 1) << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}