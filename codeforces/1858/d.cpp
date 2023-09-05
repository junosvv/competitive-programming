#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int T;
    cin >> T;
    FOR(t, 0, T) {
        int n, k;
        cin >> n >> k;
        vi a(n);
        FOR(i, 0, n) {
            char c;
            cin >> c;
            a[i] = c-'0';
        }

        auto solve = [&](vi& a) {
            vvi right(n+2, vi(k+1, n));
            ROF(i, n-1, -1) {
                if (!a[i]) right[i][0] = i;
                else right[i][0] = right[i+1][0];
            }
            FOR(t, 1, k+1) FOR(i, 0, n) right[i][t] = right[right[i][t-1] + 1][0];
            vi pref(n, a[0]);
            FOR(i, 1, n) pref[i] = a[i] + pref[i-1];

            auto query = [&](int l, int r) {
                r = min(r, n-1);
                if (l > r) return 0LL;
                if (l <= 0) return pref[r];
                return pref[r] - pref[l-1];
            };

            vi best(n+1, -1e9);
            FOR(l0, 0, n+1) {
                vi b(n, -4000);
                FOR(i, max(0LL, l0-1), n) b[i] = k - query(i-l0+1, i);
                FOR(i, 1, n) b[i] = max(b[i], b[i-1]);

                // cout << l0 << " b: ";
                // for (int i : b) cout << i << ' ';
                // cout << '\n';

                if (l0 == 0) best[l0] = max(best[l0], right[0][k]);
                FOR(i, 0, n) if (b[i] >= 0) best[l0] = max(best[l0], right[i+1][b[i]]-1-i);
            }
            return best;
        };

        vi best = solve(a);
        reverse(a.begin(), a.end());
        vi best2 = solve(a);
        FOR(i, 0, n+1) best[i] = max(best[i], best2[i]);

        // cout << "best: ";
        // for (int i : best) cout << i << ' ';
        // cout << '\n';

        FOR(j, 1, n+1) {
            int res = 0;
            FOR(l0, 0, n+1) res = max(res, j*l0 + best[l0]);
            cout << res << ' ';
        }
        cout << '\n';
    }
}