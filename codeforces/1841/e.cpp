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

    int T;
    cin >> T;
    FOR(t, 0, T) {
        int n0;
        cin >> n0;
        int n = 1;
        while (n < n0+1) n *= 2;
        vi tree(2*n, 1e9), lazy(n);
        FOR(i, 0, n0) {
            cin >> tree[n+i];
            tree[n+i] = n0 - tree[n+i];
        }
        tree[n+n0] = 0;
        ROF(i, n-1, 0) tree[i] = min(tree[2*i], tree[2*i+1]);

        int m;
        cin >> m;

        auto apply = [&](int x, int delta) {
            // cout << "        applied " << x << ' ' << delta << '\n';
            tree[x] += delta;
            if (x < n) lazy[x] += delta;
        };

        auto build = [&](int x) {
            while (x) {
                tree[x] = min(tree[2*x], tree[2*x+1]) + lazy[x];
                x /= 2;
            }
        };

        auto upd = [&](int l, int r, int delta) {
            // cout << "upd " << l << ' ' << r << ' ' << delta << '\n';
            l += n;
            r += n;
            int l0 = l, r0 = r;
            while (l <= r) {
                if (l&1) apply(l++, delta);
                if (!(r&1)) apply(r--, delta);
                l /= 2;
                r /= 2;
            }
            build(l0/2);
            build(r0/2);
        };

        function<void(int,bool)> push = [&](int x, bool rec) {
            if (rec && x > 1) push(x/2, rec);
            apply(2*x, lazy[x]);
            apply(2*x+1, lazy[x]);;
            lazy[x] = 0;
        };

        auto query = [&](int l, int r) {
            l += n;
            r += n;
            push(l/2, true);
            push(r/2, true);
            int res = 1e9;
            while (l <= r) {
                if (l&1) res = min(res, tree[l++]);
                if (!(r&1)) res = min(res, tree[r--]);
                l /= 2;
                r /= 2;
            }
            return res;
        };

        auto queryzero = [&]() {
            int x = 1;
            while (x < n) {
                push(x, false);
                if (tree[2*x] == 0) x = 2*x;
                else x = 2*x+1;
            }
            return x - n;
        };

        vvi b(n+1);
        int c = n;
        int res = 0;
        int u = 0;
        while (true) {
            // cout << "tree[1]: " << tree[1] << endl;
            while (tree[1] == 0) {
                int v = queryzero();
                upd(v, v, 1e9);
                // cout << "leftmost 0 is " << v << '\n';
                if (v-u >= 2) {
                    // cout << "component " << u << " to " << v-1 << '\n';
                    b[v-u].emplace_back(u);
                }
                u = v+1;
            }
            
            while (c >= 2 && b[c].empty()) --c;
            if (c <= 1) break;
            u = b[c].back();
            int v = u+c-1;
            b[c].pop_back();
            int k = query(u, v);
            // cout << "    comp " << u << " to " << v << " gives us " << c-1 << ' ' << k << " times" << endl;
            if (m-c*k <= 0) {
                res += m/c*(c-1);
                res += max(0LL, m%c - 1);
                break;
            }
            m -= c*k;
            res += (c-1)*k;
            upd(u, v, -k);
            upd(v+1, v+1, -1e9);
            // cout << "TREE:\n";
            // FOR(i, 0, 2*n) cout << i << ": " << tree[i] << '\n';
            // cout << endl;
        }
        cout << res << '\n';
    }
}