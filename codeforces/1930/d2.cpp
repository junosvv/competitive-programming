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
        string s;
        cin >> n >> s;

        int res = 0;
        int sz = 0;
        FOR(i, 0, n+1) {
            if (i != n && s[i] == '1') {
                ++sz;
            } else {
                int x = i - sz + 1;
                int y = n - i + 1;
                cout << "sadding " << (sz+2)/3 * x * y << '\n';
                res += (sz+2)/3 * x * y;
                FOR(k, 1, sz) {
                    cout << "adding " << (k+2)/3 * (x + y + sz - k - 1) << '\n';
                    res += (k+2)/3 * (x + y + sz - k - 1);
                }
                sz = 0;
            }
        }

        int ans = 0;
        FOR(i, 0, n) {
            vi comps;
            FOR(j, i+1, n+1) {
                comps.clear();
                int sz = 0;
                FOR(k, i, j+1) {
                    if (k != j && s[k] == '1') {
                        ++sz;
                    } else if (sz != 0) {
                        comps.push_back(sz);
                        ans += (sz+2)/3;
                        sz = 0;
                    }
                }
            }
            for (int tt : comps) cout << tt << ' ';
            cout << '\n';
        }
        cout << res << ' ' << ans << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}