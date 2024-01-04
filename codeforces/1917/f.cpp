#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

const int MOD = 998244353;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    auto solve = [&]() {
        int n, d;
        cin >> n >> d;
        vi a(n);
        FOR(i, 0, n) cin >> a[i];
        sort(a.rbegin(), a.rend());

        if (a[0] + a[1] > d) {
            cout << "No\n";
            return;
        }

        const int BIG = 2000;
        bitset<BIG> dp;
        dp[0] = 1;
        FOR(i, 1, n) {
            dp |= dp << a[i];
        }
        if (dp[d-a[0]]) {
            cout << "Yes\n";
            return;
        }

        vector<bitset<BIG>> dp2(d-a[0]+1);
        dp2[0][0] = 1;
        FOR(i, 1, n) {
            ROF(x, d-a[0], -1) {
                dp2[x] |= dp2[x] << a[i];
                if (x-a[i] >= 0) dp2[x] |= dp2[x-a[i]];
            }
        }

        FOR(x, a[0], d-a[0]+1) {
            if (dp2[x][d-x]) {
                cout << "Yes\n";
                return;
            }
        }
        cout << "No\n";
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}