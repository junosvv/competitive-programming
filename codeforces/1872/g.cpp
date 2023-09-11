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
        vi a(n);
        FOR(i, 0, n) cin >> a[i];
        vi prod(n, a[0]), pref(n, a[0]);
        FOR(i, 1, n) {
            pref[i] = a[i] + pref[i-1];
            prod[i] = a[i] * prod[i-1];
            if (prod[i] > 1e9) {
                FOR(l, 0, n) if (a[l] != 1) {
                    ROF(r, n-1, -1) if (a[r] != 1) {
                        cout << l+1 << ' ' << r+1 << '\n';
                        return;
                    }
                }
            }
        }
        vi suff(n, a[n-1]);
        ROF(i, n-2, -1) suff[i] = a[i] + suff[i+1];

        auto eval = [&](int l, int r) {
            return (l-1 >= 0 ? pref[l-1] : 0) + prod[r] / (l-1 >= 0 ? prod[l-1] : 1) + (r+1 < n ? suff[r+1] : 0);
        };
        
        vi locs;
        FOR(i, 0, n) if (a[i] >= 2) locs.push_back(i);
        if (locs.empty()) {
            cout << "1 1\n";
            return;
        }

        int m = locs.size();
        int resL = -1, resR;
        FOR(i, 0, m) FOR(j, i, m) {
            if (resL == -1 || eval(locs[i], locs[j]) > eval(resL, resR)) {
                resL = locs[i];
                resR = locs[j];
            }
        }
        cout << resL+1 << ' ' << resR+1 << '\n';
    };
    
    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}