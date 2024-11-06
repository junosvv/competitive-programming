#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

const int MOD = 1e9+7;

int powa(int base, int exp) {
    int res = 1;
    while (exp) {
        if (exp&1) res = res * base % MOD;
        base = base * base % MOD;
        exp /= 2;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    auto solve = [&]() {
        int n;
        cin >> n;
        vi a(n);
        FOR(i, 0, n) cin >> a[i];

        vi res, locs, tree(2*n), key(2*n);
        FOR(i, 0, n) key[n+i] = i;
        auto upd = [&](int x, int val) {
            x += n;
            tree[x] = val;
            x /= 2;
            while (x) {
                tree[x] = max(tree[2*x], tree[2*x+1]);
                if (tree[2*x] > tree[2*x+1]) key[x] = key[2*x];
                else key[x] = key[2*x+1];
                x /= 2;
            }
        };
        auto query = [&](int l, int r) {
            int res = 0;
            l += n;
            r += n;
            while (l <= r) {
                if (l&1) res = max(res, tree[l++]);
                if (!(r&1)) res = max(res, tree[r--]);
                l /= 2;
                r /= 2;
            }
            return res;
        };
        auto query_key = [&](int l, int r) {
            int res = l;
            l += n;
            r += n;
            while (l <= r) {
                if (l&1) {
                    if (tree[l] > tree[n+res]) res = key[l];
                    ++l;
                }
                if (!(r&1)) {
                    if (tree[r] > tree[n+res]) res = key[r];
                    --r;
                }
                l /= 2;
                r /= 2;
            }
            return res;
        };

        int sm = 0;
        FOR(i, 0, n) {
            while (a[i] % 2 == 0) {
                locs.push_back(i);
                a[i] /= 2;
            }
            upd(i, a[i]);
            sm += a[i];
            int cur = sm;

            if (!locs.empty()) {
                vi updated;
                ROF(j, locs.size()-1, -1) {
                    int mx = query(locs[j], i);
                    int ky = query_key(locs[j], i);
                    upd(ky, 2*mx);
                    updated.push_back(ky);
                    cur += mx;
                    if (2*mx > 1e9) {
                        // cout << j << " remaining " << 2*mx << "\n";
                        // cout << "before: " << cur << '\n';
                        cur = (cur%MOD + 2*mx%MOD * ((powa(2, j)+MOD-1) % MOD) % MOD) % MOD;
                        break;
                    }
                }
                for (int i : updated) upd(i, a[i]);
            }
            cur %= MOD;
            cout << cur << ' ';
        }
        cout << '\n';
    };
    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}