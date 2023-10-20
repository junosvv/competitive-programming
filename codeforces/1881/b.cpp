#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

const int MOD = 998244353;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int T;
    cin >> T;
    FOR(ti, 0, T) {
        vi a(3);
        FOR(i, 0, 3) cin >> a[i];
        
        auto solve = [&](int ops) {
            int k = a[0] + a[1] + a[2];
            if (k % (3+ops)) return false;
            k /= 3+ops;

            int res = 0;
            FOR(i, 0, 3) {
                if (a[i] % k) return false;
                res += a[i]/k - 1;
            }
            return res <= ops;
        };

        cout << (solve(0) || solve(1) || solve(2) || solve(3) ? "YES" : "NO") << '\n';
    }
}