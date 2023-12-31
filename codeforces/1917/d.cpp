#include <bits/stdc++.h>
using namespace std;

#define lg long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

const int MOD = 998244353;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    auto solve = [&]() {
        int n, k;
        cin >> n >> k;
        vi p(n), q(k);
        FOR(i, 0, n) cin >> p[i];
        FOR(i, 0, k) cin >> q[i];

        vi tree(2*k);
        int sz = k;
        auto upd = [&](int x, int delta) {
            x += sz;
            tree[x] += delta;
            x /= 2;
            while (x) {
                tree[x] = tree[2*x] + tree[2*x+1];
                x /= 2;
            }
        };

        auto query = [&](int l, int r) {
            if (r < 0 || l >= sz) return 0;
            l = max(l, 0);
            r = min(r, sz-1);
            l += sz;
            r += sz;
            int res = 0;
            while (l <= r) {
                if (l&1) res += tree[l++];
                if (!(r&1)) res += tree[r--];
                l /= 2;
                r /= 2;
            }
            return res;
        };

        lg res = 0;
        FOR(i, 0, k) {
            res = (res + query(q[i], k)) % MOD;
            upd(q[i], 1);
        }
        res = res * n % MOD;

        // cout << "init " << res << '\n';

        sz = 2e5;
        tree.assign(2*sz, 0);
        FOR(i, 0, n) {
            // cout << "proc " << p[i] << '\n';
            lg cur = k*(k+1)/2;
            FOR(b, 0, 20) {
                // cout << query(p[i]*(1<<b), p[i]*(1<<b+1)) << " get " << cur << '\n';
                if (p[i] >= ((int)2e5+2)>>b) break;
                if (cur/k == k) {
                    res = (res + cur * query(p[i]*(1<<b), 2e5)) % MOD;
                    break;
                }
                res = (res + cur * query(p[i]*(1<<b), p[i]*(1<<b+1))) % MOD;
                cur += k-1-b;
            }
            FOR(b, 0, 20) {
                lg cur = (k-1-b)*(k-b)/2;
                if (cur <= 0 || (1<<b) > p[i]) break;
                int denom = 1<<b+1;
                // cout << query((p[i]+denom-1)/denom, p[i]/(1<<b)) << " get " << (k-1-b)*(k-b)/2 << '\n';
                res = (res + (k-1-b)*(k-b)/2 * query((p[i]+denom-1)/denom, p[i]/(1<<b))) % MOD;
            }
            upd(p[i], 1);
        }
        cout << res << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}