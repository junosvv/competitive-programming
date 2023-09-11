#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    auto solve = [&]() {
        int n;
        cin >> n;
        vi a(n);
        FOR(i, 0, n) cin >> a[i];
        string s;
        cin >> s;
        vi ans(2);
        FOR(i, 0, n) ans[s[i]-'0'] ^= a[i];
        vi pref = a;
        FOR(i, 1, n) pref[i] ^= pref[i-1];
        auto query = [&](int l, int r) {
            return pref[r] ^ (l-1 >= 0 ? pref[l-1] : 0);
        };
        int q;
        cin >> q;
        FOR(qi, 0, q) {
            int tp;
            cin >> tp;
            if (tp == 1) {
                int l, r;
                cin >> l >> r;
                --l; --r;
                int cur = query(l, r);
                ans[0] ^= cur;
                ans[1] ^= cur;
            } else {
                int x;
                cin >> x;
                cout << ans[x] << ' ';
            }
        }
        cout << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}